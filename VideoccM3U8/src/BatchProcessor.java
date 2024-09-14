import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class BatchProcessor {

    public static void main(String[] args) {
        // 从 Main 类获取 urls.txt 文件的路径
        String filePath = Main.URLS_FILE_PATH;

        // 从控制台获取用户输入的起始行号
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the starting line number: ");
        int startLine = scanner.nextInt();

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            int currentLine = 0;

            // 逐行读取文件内容
            while ((line = br.readLine()) != null) {
                currentLine++;

                // 跳过之前的行，从指定行开始处理
                if (currentLine < startLine) {
                    continue;
                }

                // 打印当前处理的URL
                System.out.println("Processing URL at line " + currentLine + ": " + line);

                // 将 URL 传递给 Main 类进行处理
                Main.main(new String[]{line});
            }

        } catch (IOException e) {
            // 异常处理
            System.err.println("Error reading file: " + e.getMessage());
        }
    }
}