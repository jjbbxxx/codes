import java.io.*;
import java.util.*;

public class QuestionInput {
    private static final String FILE_PATH = "questions.txt";
    private Map<String, List<String>> questions = new LinkedHashMap<>();
    private Scanner scanner = new Scanner(System.in);

    // 构造方法：加载现有题库
    public QuestionInput() {
        loadQuestions();
    }

    // 主菜单
    public void start() {
        while (true) {
            System.out.println("请选择要录入的题目类型：");
            System.out.println("1. 选择题");
            System.out.println("2. 填空题");
            System.out.println("3. 退出");
            System.out.print("请输入选项（1/2/3）：");

            String choice = scanner.nextLine();
            switch (choice) {
                case "1":
                    addChoiceQuestion();
                    break;
                case "2":
                    addFillInBlankQuestion();
                    break;
                case "3":
                    saveQuestions();
                    System.out.println("题目已保存到题库。程序退出。");
                    return;
                default:
                    System.out.println("无效选项，请重新输入。");
            }
        }
    }

    // 录入选择题
    private void addChoiceQuestion() {
        System.out.print("请输入主题名：");
        String theme = scanner.nextLine().trim();

        String storedTheme;

        // 检查主题是否已存在
        boolean themeExists = questions.containsKey("[" + theme + "]") || questions.containsKey("{" + theme + "}");

        if (themeExists) {
            // 如果主题已存在，保持原有格式（方括号或花括号）
            if (questions.containsKey("[" + theme + "]")) {
                storedTheme = "[" + theme + "]";
            } else {
                storedTheme = "{" + theme + "}";
            }
            System.out.println("在已有主题 \"" + theme + "\" 下添加新题目。");
        } else {
            // 如果主题不存在，询问格式选择
            System.out.println("请选择题干格式：");
            System.out.println("1. \"" + theme + "的[题目词]是什么？\"");
            System.out.println("2. \"[题目词]是" + theme + "的什么？\"");
            System.out.print("请输入选项（1/2）：");
            String formatChoice = scanner.nextLine().trim();

            if (formatChoice.equals("1")) {
                storedTheme = "[" + theme + "]";
            } else if (formatChoice.equals("2")) {
                storedTheme = "{" + theme + "}";
            } else {
                System.out.println("无效选项，默认使用方括号。");
                storedTheme = "[" + theme + "]";
            }

            // 添加新主题
            questions.putIfAbsent(storedTheme, new ArrayList<>());
        }

        while (true) {
            System.out.print("请输入题目词：");
            String questionTerm = scanner.nextLine().trim();

            System.out.print("请输入答案：");
            String answer = scanner.nextLine().trim();

            System.out.print("请输入联想方法（回车跳过）：");
            String hint = scanner.nextLine().trim();

            String entry = hint.isEmpty() ? questionTerm + "|" + answer : questionTerm + "|" + answer + "|" + hint;
            questions.get(storedTheme).add(entry);

            System.out.println("表述已添加：" + entry);

            System.out.print("回车继续在当前主题 \"" + theme + "\" 下录入，输入“q”更换主题：");
            String input = scanner.nextLine().trim();
            if (input.equals("q")) {
                break;
            }
        }
    }

    // 录入填空题
    private void addFillInBlankQuestion() {
        System.out.print("请输入填空题的题干（使用括号“（）”表示空）：");
        String question = scanner.nextLine().trim();

        System.out.println("请输入答案（在新一行输入“。”结束）：");
        StringBuilder answerBuilder = new StringBuilder();
        String line;
        while (true) {
            line = scanner.nextLine();
            if (line.trim().equals("。")) {
                break;
            }
            // 将每行添加到答案中，并在行末附加字符串 "\n"
            answerBuilder.append(line).append("\\n");
        }

        // 删除末尾多余的 \n 符号
        if (answerBuilder.length() > 2) {
            answerBuilder.setLength(answerBuilder.length() - 2);
        }

        String answer = answerBuilder.toString().trim();
        String entry = question + "|" + answer;

        String storedTheme = "<填空题>";

        if (!questions.containsKey(storedTheme)) {
            questions.put(storedTheme, new ArrayList<>());
        }

        // 添加填空题到填空题部分的末尾
        questions.get(storedTheme).add(entry);

        System.out.println("填空题已添加：" + entry);
    }

    // 加载题库
    private void loadQuestions() {
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_PATH))) {
            String line;
            String currentTheme = null;
            Map<String, List<String>> tempQuestions = new LinkedHashMap<>();

            while ((line = reader.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) continue;

                if (line.startsWith("[") || line.startsWith("{") || line.startsWith("<")) {
                    currentTheme = line;
                    tempQuestions.putIfAbsent(currentTheme, new ArrayList<>());
                } else if (currentTheme != null) {
                    tempQuestions.get(currentTheme).add(line);
                }
            }

            // 将填空题先加载，然后加载选择题
            for (Map.Entry<String, List<String>> entry : tempQuestions.entrySet()) {
                if (entry.getKey().equals("<填空题>")) {
                    questions.put(entry.getKey(), entry.getValue());
                }
            }
            for (Map.Entry<String, List<String>> entry : tempQuestions.entrySet()) {
                if (!entry.getKey().equals("<填空题>")) {
                    questions.put(entry.getKey(), entry.getValue());
                }
            }
        } catch (IOException e) {
            System.out.println("未找到现有题库，将创建新题库文件。");
        }
    }

    // 保存题库
    private void saveQuestions() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_PATH))) {
            for (Map.Entry<String, List<String>> entry : questions.entrySet()) {
                String theme = entry.getKey();
                List<String> questionList = entry.getValue();

                if (theme.equals("<填空题>")) {
                    // 为每一道填空题单独写入 <填空题> 主题行
                    for (String question : questionList) {
                        writer.write("<填空题>");
                        writer.newLine();
                        writer.write(question);
                        writer.newLine();
                        writer.newLine(); // 添加空行分隔题目
                    }
                } else {
                    // 选择题按原格式保存
                    writer.write(theme);
                    writer.newLine();
                    for (String question : questionList) {
                        writer.write(question);
                        writer.newLine();
                    }
                    writer.newLine(); // 添加空行分隔主题
                }
            }
        } catch (IOException e) {
            System.out.println("保存题库时发生错误：" + e.getMessage());
        }
    }

    // 主程序入口
    public static void main(String[] args) {
        new QuestionInput().start();
    }
}