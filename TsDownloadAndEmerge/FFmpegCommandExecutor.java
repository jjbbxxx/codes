import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class FFmpegCommandExecutor {

    public static void main(String[] args) {
        // 构建命令和参数
        // 使用 LocalDateTime 获取当前时间
        LocalDateTime now = LocalDateTime.now();
        // 格式化时间为如 '2022-05-28_15-30-00' 这样的格式
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyyMMdd_HHmmss");
        String currentTime = now.format(formatter);

        String outputFileName = "C:\\Users\\asus\\Downloads\\TSDownload\\out_" + currentTime + ".mp4";

        String[] command = {
                ".\\ffmpeg",
                "-allowed_extensions", "ALL",
                "-protocol_whitelist", "file,http,crypto,tcp",
                "-i", "C:\\Users\\asus\\Downloads\\TSDownload\\cache\\index.m3u8",
                "-c", "copy",
                outputFileName
        };

        // 指定FFmpeg所在的目录（如果FFmpeg不在系统路径中）
        String ffmpegDirectory = "E:\\jbx\\Code\\TsDownloadAndEmerge"; // 替换为您FFmpeg的实际路径

        ProcessBuilder processBuilder = new ProcessBuilder(command);
        processBuilder.directory(new java.io.File(ffmpegDirectory)); // 设置工作目录
        processBuilder.redirectErrorStream(true); // 合并标准输出和标准错误输出

        try {
            Process process = processBuilder.start();
            // 读取和打印命令输出
            java.io.InputStream inputStream = process.getInputStream();
            java.util.Scanner scanner = new java.util.Scanner(inputStream).useDelimiter("\\A");
            String output = scanner.hasNext() ? scanner.next() : "";
            System.out.println(output);

            int exitCode = process.waitFor();
            System.out.println("Exited with error code : " + exitCode);
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
