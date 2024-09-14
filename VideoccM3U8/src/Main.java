import java.io.File;

public class Main {
    // 统一的输出目录，只需在此修改输出路径
    public static final String OUTPUT_DIRECTORY = "/path/to/output"; // 用户只需修改这行
    public static final String CACHE_DIRECTORY = OUTPUT_DIRECTORY + "/cache";
    public static final String DOWNLOADED_M3U8_FILE = CACHE_DIRECTORY + "/downloaded.m3u8";
    public static final String MODIFIED_M3U8_FILE = CACHE_DIRECTORY + "/modified.m3u8";
    public static final String DOWNLOADED_KEY_FILE = CACHE_DIRECTORY + "/downloaded.key";
    public static final String SEGMENTS_DIRECTORY = CACHE_DIRECTORY;
    public static final String FILENAMES_LIST_PATH = OUTPUT_DIRECTORY + "/filenames.txt";
    public static final String URLS_FILE_PATH = CACHE_DIRECTORY + "/urls.txt"; // 新增urls.txt路径

    public static void main(String[] args) {
        // 创建必要的目录
        createDirectory();

        // 清理上次下载和修改的文件
        CleanupManager.cleanUp(CACHE_DIRECTORY);

        // 获取输入的 URL 并处理
        String m3u8Url = args.length > 0 ? args[0] : null;
        if (m3u8Url == null) {
            System.err.println("URL not provided.");
            return;
        }

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
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
            System.exit(1);
        }
    }

    // 创建目录
    private static void createDirectory() {
        File directory = new File(Main.CACHE_DIRECTORY);
        if (!directory.exists()) {
            if (directory.mkdirs()) {
                System.out.println("Created directory: " + Main.CACHE_DIRECTORY);
            } else {
                System.err.println("Failed to create directory: " + Main.CACHE_DIRECTORY);
            }
        }
    }
}