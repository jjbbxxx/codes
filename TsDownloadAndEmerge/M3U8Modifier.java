import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class M3U8Modifier {

    public static void main(String[] args) {
        String filePath = "path/to/your/index.m3u8"; // 指定M3U8文件路径

        modifyM3U8File(filePath);
    }

    private static void modifyM3U8File(String filePath) {
        StringBuilder contentBuilder = new StringBuilder();

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                if (line.contains("URI=\"./enc.key\"")) {
                    line = line.replace("URI=\"./enc.key\"", "URI=\"enc.key\"");
                }
                contentBuilder.append(line).append(System.lineSeparator());
            }
            writeToFile(filePath, contentBuilder.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void writeToFile(String filePath, String content) throws IOException {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePath))) {
            bw.write(content);
        }
    }
}
