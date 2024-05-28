import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class FFmpegExecutor {

    private static final String FFMPEG_PATH = "E:/jbx/Code/TsDownloadAndEmerge/ffmpeg.exe";
    private static final String OUTPUT_DIRECTORY = "E:/研途/数据结构";
    private static final String CACHE_DIRECTORY = OUTPUT_DIRECTORY + "/cache";
    private static final String MODIFIED_M3U8_FILE = CACHE_DIRECTORY + "/modified.m3u8";
    private static final String FILENAMES_LIST_PATH = CACHE_DIRECTORY + "/filenames.txt";

    public static void main(String[] args) {
        try {
            executeFFmpeg(MODIFIED_M3U8_FILE, OUTPUT_DIRECTORY, FILENAMES_LIST_PATH);
            System.out.println("MP4 file created successfully.");
        } catch (IOException | InterruptedException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    public static void executeFFmpeg(String m3u8FilePath, String outputDirectory, String filenamesListPath) throws IOException, InterruptedException {
        System.out.println("Starting FFmpeg execution...");

        // 读取文件名列表
        List<String> filenames = Files.readAllLines(Paths.get(filenamesListPath));
        System.out.println("File names list read successfully.");

        // 获取输出目录中已有视频文件的数量
        File outputDir = new File(outputDirectory);
        if (!outputDir.exists()) {
            outputDir.mkdirs();
        }
        File[] files = outputDir.listFiles((dir, name) -> name.endsWith(".mp4"));
        int videoCount = (files != null) ? files.length : 0;

        // 确定输出文件名
        String outputFileName = filenames.get(videoCount) + ".mp4";
        String outputMp4Path = outputDirectory + "/" + outputFileName;
        System.out.println("Output file name determined: " + outputFileName);

        // 构建 FFmpeg 命令
        String[] ffmpegCommand = {
                FFMPEG_PATH,
                "-allowed_extensions", "ALL",
                "-protocol_whitelist", "file,http,crypto,tcp,https,tls",
                "-i", m3u8FilePath,
                "-c", "copy",
                outputMp4Path
        };
        System.out.println("FFmpeg command: " + String.join(" ", ffmpegCommand));

        // 使用 ProcessBuilder 执行 FFmpeg 命令
        ProcessBuilder processBuilder = new ProcessBuilder(ffmpegCommand);
        processBuilder.redirectErrorStream(true);  // 将错误流和标准流合并
        processBuilder.inheritIO(); // 直接使用当前进程的标准输出和标准错误流
        Process process = processBuilder.start();
        System.out.println("FFmpeg process started.");

        process.waitFor();
        System.out.println("FFmpeg process completed.");

        if (process.exitValue() != 0) {
            throw new IOException("FFmpeg command failed with exit code " + process.exitValue());
        }
    }
}
