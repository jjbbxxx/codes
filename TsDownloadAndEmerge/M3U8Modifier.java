import java.io.*;

public class M3U8Modifier {

    public static void main(String[] args) {
        String filePath = "C:\\Users\\asus\\Downloads\\TSDownload\\cache\\index.m3u8"; // 指定M3U8文件路径

        modifyM3U8File(filePath);
    }

    private static void modifyM3U8File(String filePath) {
        StringBuilder contentBuilder = new StringBuilder();
        boolean modified = false;

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            int lineNumber = 0;

            while ((line = br.readLine()) != null) {
                lineNumber++;
                if (lineNumber == 5 && line.contains("URI=\"./enc.key\"")) {
                    line = line.replace("URI=\"./enc.key\"", "URI=\"enc.key\"");
                    modified = true;
                }
                contentBuilder.append(line).append(System.lineSeparator());
            }

            // 如果进行了修改，则重写文件
            if (modified) {
                writeToFile(filePath, contentBuilder.toString());
            }
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
