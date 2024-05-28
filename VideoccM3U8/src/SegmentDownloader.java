import java.io.*;
import java.net.URL;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SegmentDownloader {

    public static void downloadSegments(String m3u8FilePath, String outputDirectory) throws IOException, InterruptedException {
        File inputFile = new File(m3u8FilePath);
        createDirectoryIfNotExists(outputDirectory);
        File outputDir = new File(outputDirectory);
        if (!outputDir.exists()) {
            outputDir.mkdirs();
        }

        Pattern segmentPattern = Pattern.compile("^(.*\\.ts)$");
        ExecutorService executor = Executors.newFixedThreadPool(10); // 使用10个线程下载分段

        // Read the m3u8 file and download each segment
        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                Matcher matcher = segmentPattern.matcher(line);
                if (matcher.matches()) {
                    String segmentUrl = line.trim();
                    String segmentFileName = segmentUrl.substring(segmentUrl.lastIndexOf("/") + 1);
                    System.out.println("Queueing download for segment: " + segmentFileName);
                    executor.submit(() -> {
                        try {
                            downloadSegment(segmentUrl, outputDirectory + "/" + segmentFileName);
                            System.out.println("Downloaded segment: " + segmentFileName);
                        } catch (IOException e) {
                            System.err.println("Failed to download segment: " + segmentFileName);
                        }
                    });
                }
            }
        }

        executor.shutdown();
        executor.awaitTermination(Long.MAX_VALUE, TimeUnit.MILLISECONDS); // 等待所有任务完成
    }

    private static void downloadSegment(String segmentUrl, String outputFilePath) throws IOException {
        createDirectoryIfNotExists(outputFilePath);
        URL url = new URL(segmentUrl);
        try (BufferedInputStream in = new BufferedInputStream(url.openStream());
             FileOutputStream fileOutputStream = new FileOutputStream(outputFilePath)) {
            byte[] dataBuffer = new byte[1024];
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
