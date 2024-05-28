import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static final String OUTPUT_DIRECTORY = "E:/研途/数据结构";
    public static final String CACHE_DIRECTORY = OUTPUT_DIRECTORY + "/cache";
    public static final String DOWNLOADED_M3U8_FILE = CACHE_DIRECTORY + "/downloaded.m3u8";
    public static final String MODIFIED_M3U8_FILE = CACHE_DIRECTORY + "/modified.m3u8";
    public static final String DOWNLOADED_KEY_FILE = CACHE_DIRECTORY + "/downloaded.key";
    public static final String SEGMENTS_DIRECTORY = CACHE_DIRECTORY;

    public static void main(String[] args) {
        // 创建必要的目录
        createDirectory(CACHE_DIRECTORY);

        // 清理上次下载和修改的文件
        CleanupManager.cleanUp(CACHE_DIRECTORY);

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the URL of the m3u8 file: ");
        String m3u8Url = scanner.nextLine();

        try {
            System.out.println("Downloading m3u8 file...");
            M3U8FileDownloader.downloadM3U8File(m3u8Url, DOWNLOADED_M3U8_FILE);
            System.out.println("m3u8 file downloaded successfully to " + DOWNLOADED_M3U8_FILE);

            System.out.println("Modifying m3u8 file...");
            String keyUrl = M3U8Modifier.modifyM3U8File(DOWNLOADED_M3U8_FILE, MODIFIED_M3U8_FILE);
            System.out.println("m3u8 file modified successfully and saved to " + MODIFIED_M3U8_FILE);

            System.out.println("Downloading key file...");
            KeyFileDownloader.downloadKeyFile(keyUrl, DOWNLOADED_KEY_FILE);
            System.out.println("key file downloaded successfully to " + DOWNLOADED_KEY_FILE);

            System.out.println("Downloading segments...");
            SegmentDownloader.downloadSegments(MODIFIED_M3U8_FILE, SEGMENTS_DIRECTORY);
            System.out.println("Segments downloaded successfully to " + SEGMENTS_DIRECTORY);

            // 调用 FFmpegExecutor
            System.out.println("Starting FFmpeg execution...");
            FFmpegExecutor.main(null);
        } catch (IOException | InterruptedException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    private static void createDirectory(String directoryPath) {
        File directory = new File(directoryPath);
        if (!directory.exists()) {
            if (directory.mkdirs()) {
                System.out.println("Created directory: " + directoryPath);
            } else {
                System.err.println("Failed to create directory: " + directoryPath);
            }
        }
    }
}
