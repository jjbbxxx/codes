import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;

public class M3U8Generator {
    public static void complete(int totalSegments) {
        // 设置输入和输出文件路径，以及所需的总分段数
        FileRenamer.rename();
        String inputFilePath = "C:\\Users\\asus\\Downloads\\TSDownload\\cache\\index0.m3u8"; // 输入的m3u8文件路径
        String outputFilePath = "C:\\Users\\asus\\Downloads\\TSDownload\\cache\\index.m3u8"; // 输出的m3u8文件路径

        try {
            generateCompleteM3U8(inputFilePath, outputFilePath, totalSegments);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void generateCompleteM3U8(String inputFilePath, String outputFilePath, int totalSegments) throws IOException {
        // 读取输入文件的全部内容
        String content = new String(Files.readAllBytes(Paths.get(inputFilePath)));
        BufferedWriter writer = new BufferedWriter(new FileWriter(outputFilePath));

        String[] lines = content.split("\n");
        boolean segmentFound = false;
        String segmentTemplate = null;
        String extinfDuration = null;

        // 写入原始的头信息，寻找EXTINF行，并提取分段模板
        for (String line : lines) {
            writer.write(line.trim());
            writer.newLine();
            if (line.startsWith("#EXTINF")) {
                segmentFound = true;
                extinfDuration = line.split(":")[1].split(",")[0];
                segmentTemplate = lines[lines.length - 1].replaceAll("\\d+\\.ts", ""); // 找到并提取文件名前缀
                break;
            }
        }

        // 如果找到了EXTINF行，生成其他分段并写入文件
        if (segmentFound) {
            for (int i = 1; i <= totalSegments; i++) {
                String segmentName = String.format(segmentTemplate + "%03d.ts", i);
                writer.write("#EXTINF:" + extinfDuration + ",");
                writer.newLine();
                writer.write(segmentName);
                writer.newLine();
            }
            writer.write("#EXT-X-ENDLIST");
        } else {
            System.err.println("Unable to generate complete M3U8: Missing EXTINF section.");
        }
        writer.close();
    }
}
