import java.io.*;
import java.util.*;

public class QuizRunner {
    private static final String FILE_PATH = "questions.txt";
    private List<Question> allQuestions = new ArrayList<>();
    private Scanner scanner = new Scanner(System.in);
    private Random random = new Random();

    // 构造方法：加载题库
    public QuizRunner() {
        loadQuestions();
    }

    // 主方法，启动出题循环
    public void start() {
        System.out.println("欢迎使用出题系统！（输入“q”退出系统）\n");

        while (true) {
            generateRandomQuestion();

            System.out.print("\n按回车继续，输入“q”退出系统：");
            String input = scanner.nextLine().trim();

            if (input.equalsIgnoreCase("q")) {
                System.out.println("感谢使用出题系统，程序退出。");
                break;
            }
        }
    }

    private void generateRandomQuestion() {
        if (allQuestions.isEmpty()) {
            System.out.println("题库为空，请先录入题目。");
            return;
        }

        // 随机选择一个题目
        Question question = allQuestions.get(random.nextInt(allQuestions.size()));

        if (question.isFillInBlank()) {
            generateFillInBlankQuestion(question);
        } else {
            generateChoiceQuestion(question);
        }
    }

    // 生成选择题
    private void generateChoiceQuestion(Question question) {
        String[] parts = question.getContent().split("\\|");
        String theme = question.getTheme();
        String questionTerm = parts[0];
        String correctAnswer = parts[1];
        String hint = parts.length == 3 ? parts[2] : "";

        // 收集所有可能的答案
        Set<String> allAnswers = new LinkedHashSet<>();
        allAnswers.add(correctAnswer);

        for (Question q : allQuestions) {
            String[] qParts = q.getContent().split("\\|");
            if (q.getTheme().equals(theme) && qParts.length >= 2 && !qParts[1].equals(correctAnswer)) {
                allAnswers.add(qParts[1]);
            }
        }

        // 将答案集合转换为列表并打乱顺序
        List<String> answerList = new ArrayList<>(allAnswers);
        Collections.shuffle(answerList);

        // 保证最多只有四个选项（一个正确答案和三个随机错误答案）
        List<String> options = new ArrayList<>();
        options.add(correctAnswer);
        for (String answer : answerList) {
            if (options.size() == 4) break;
            if (!answer.equals(correctAnswer)) {
                options.add(answer);
            }
        }
        Collections.shuffle(options);

        // 生成题干
        String questionText;
        String cleanTheme = theme.trim(); // 去除主题名的首尾空格

        if (cleanTheme.startsWith("{") && cleanTheme.endsWith("}")) {
            questionText = questionTerm + "是" + cleanTheme.substring(1, cleanTheme.length() - 1) + "的（    ）";
        } else if (cleanTheme.startsWith("[") && cleanTheme.endsWith("]")) {
            questionText = cleanTheme.substring(1, cleanTheme.length() - 1) + "的" + questionTerm + "是（    ）";
        } else {
            // 如果没有匹配到括号，保持默认格式
            questionText = cleanTheme + "的" + questionTerm + "是（    ）";
        }

        System.out.println("\n" + questionText);

        // 显示选项
        char optionLetter = 'A';
        for (String option : options) {
            System.out.println(optionLetter + ". " + option);
            optionLetter++;
        }

        // 获取用户答案
        System.out.print("请输入你的答案：");
        String userAnswer = scanner.nextLine().trim().toUpperCase();

        // 判断答案
        int correctIndex = options.indexOf(correctAnswer);
        char correctOption = (char) ('A' + correctIndex);

        if (userAnswer.length() == 1 && userAnswer.charAt(0) == correctOption) {
            System.out.println("回答正确！");
        } else {
            // 输出正确答案和提示信息，使用中文引号括起提示内容
            if (!hint.isEmpty()) {
                System.out.println("回答错误！正确答案是 " + correctOption + ". " + correctAnswer + "——“" + hint + "”");
            } else {
                System.out.println("回答错误！正确答案是 " + correctOption + ". " + correctAnswer);
            }
        }
    }

    // 生成填空题
    private void generateFillInBlankQuestion(Question question) {
        String[] parts = question.getContent().split("\\|");
        String questionText = parts[0];
        String answer = parts[1].replace("\\n", "\n"); // 将 \n 替换回实际换行

        // 将括号（）替换为下划线____
        String displayedQuestion = questionText.replaceAll("（.*?）", "____");

        System.out.println("\n" + displayedQuestion);
        System.out.print("按回车查看答案...");
        scanner.nextLine();

        System.out.println("答案：\n" + answer);
    }

    // 加载题库
    private void loadQuestions() {
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_PATH))) {
            String line;
            String currentTheme = null;

            while ((line = reader.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) continue;

                if (line.startsWith("<") && line.endsWith(">")) {
                    // 识别填空题的主题
                    currentTheme = line;
                } else if (line.startsWith("[") || line.startsWith("{")) {
                    // 识别选择题的主题
                    currentTheme = line;
                } else if (currentTheme != null) {
                    // 添加题目
                    allQuestions.add(new Question(currentTheme, line));
                }
            }
        } catch (IOException e) {
            System.out.println("加载题库失败：" + e.getMessage());
        }
    }

    // 内部类表示题目
    private static class Question {
        private String theme;
        private String content;

        public Question(String theme, String content) {
            this.theme = theme;
            this.content = content;
        }

        public String getTheme() {
            return theme;
        }

        public String getContent() {
            return content;
        }

        public boolean isFillInBlank() {
            return theme.trim().equalsIgnoreCase("<填空题>");
        }
    }

    // 主程序入口
    public static void main(String[] args) {
        new QuizRunner().start();
    }
}