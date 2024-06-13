import java.io.BufferedInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.File;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SegmentDownloader {

    private static final int MAX_RETRIES = 10;
    private static boolean downloadFailed = false; // 标志变量，用于指示是否有下载失败

    public static void downloadSegments(String m3u8FilePath, String outputDirectory) throws IOException, InterruptedException {
        // 设置系统属性以使用系统代理配置
        System.setProperty("java.net.useSystemProxies", "true");

        // 创建必要的目录
        createDirectoryIfNotExists(outputDirectory);
        Pattern segmentPattern = Pattern.compile("^(.*\\.ts)$");
        ExecutorService executor = Executors.newFixedThreadPool(10); // 使用10个线程下载分段

        // 读取 m3u8 文件并下载每个分段
        try (BufferedReader reader = new BufferedReader(new java.io.FileReader(m3u8FilePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                Matcher matcher = segmentPattern.matcher(line);
                if (matcher.matches()) {
                    String segmentUrl = line.trim();
                    String segmentFileName = segmentUrl.substring(segmentUrl.lastIndexOf("/") + 1);
                    System.out.println("Queueing download for segment: " + segmentFileName);
                    executor.submit(() -> {
                        boolean success = false;
                        int attempts = 0;
                        while (!success && attempts < MAX_RETRIES) {
                            try {
                                downloadSegment(segmentUrl, outputDirectory + "/" + segmentFileName);
                                System.out.println("Downloaded segment: " + segmentFileName);
                                success = true;
                            } catch (IOException e) {
                                attempts++;
                                System.err.println("Failed to download segment: " + segmentFileName + ", attempt: " + attempts);
                                if (attempts >= MAX_RETRIES) {
                                    System.err.println("Exceeded max retries for segment: " + segmentFileName);
                                    downloadFailed = true; // 标记下载失败
                                    break;
                                }
                            }
                        }
                    });
                }
            }
        }

        executor.shutdown();
        executor.awaitTermination(Long.MAX_VALUE, TimeUnit.MILLISECONDS); // 等待所有任务完成

        // 如果有下载失败，抛出异常停止程序
        if (downloadFailed) {
            throw new IOException("One or more segments failed to download after maximum retries. Stopping the program.");
        }
    }

    private static void downloadSegment(String segmentUrl, String outputFilePath) throws IOException {
        // 设置系统属性以使用系统代理配置
        System.setProperty("java.net.useSystemProxies", "true");

        URL url = new URL(segmentUrl);
        HttpURLConnection connection = (HttpURLConnection) url.openConnection();

        connection.setConnectTimeout(10000);
        connection.setReadTimeout(10000);

        try (InputStream in = new BufferedInputStream(connection.getInputStream());
             FileOutputStream fileOutputStream = new FileOutputStream(outputFilePath)) {
            byte dataBuffer[] = new byte[1024];
            int bytesRead;
            while ((bytesRead = in.read(dataBuffer, 0, 1024)) != -1) {
                fileOutputStream.write(dataBuffer, 0, bytesRead);
            }
        }
    }

    private static void createDirectoryIfNotExists(String filePath) {
        File file = new File(filePath);
        File parentDir = file.getParentFile();
        if (parentDir != null && !parentDir.exists()) {
            parentDir.mkdirs();
        }
    }
}
