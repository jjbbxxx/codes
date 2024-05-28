import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicLong;

public class Ev1FileDownloader {

    private static final int THREAD_COUNT = 32; // 线程数
    private final AtomicLong totalBytesRead = new AtomicLong(0);

    public String downloadFile(String fileURL, String saveDir) throws IOException, InterruptedException {
        URL url = new URL(fileURL);
        HttpURLConnection httpConn = (HttpURLConnection) url.openConnection();
        int responseCode = httpConn.getResponseCode();

        if (responseCode == HttpURLConnection.HTTP_OK) {
            String fileName = "";
            String disposition = httpConn.getHeaderField("Content-Disposition");
            String contentType = httpConn.getContentType();
            int contentLength = httpConn.getContentLength();

            if (disposition != null) {
                int index = disposition.indexOf("filename=");
                if (index > 0) {
                    fileName = disposition.substring(index + 10, disposition.length() - 1);
                }
            } else {
                int queryIndex = fileURL.indexOf("?");
                fileName = fileURL.substring(fileURL.lastIndexOf("/") + 1, (queryIndex > 0) ? queryIndex : fileURL.length());
            }

            System.out.println("Content-Type = " + contentType);
            System.out.println("Content-Disposition = " + disposition);
            System.out.println("Content-Length = " + contentLength);
            System.out.println("fileName = " + fileName);

            String saveFilePath = saveDir + "/" + fileName;

            ExecutorService executor = Executors.newFixedThreadPool(THREAD_COUNT);
            int partSize = contentLength / THREAD_COUNT;

            long startTime = System.currentTimeMillis();
            for (int i = 0; i < THREAD_COUNT; i++) {
                int startByte = i * partSize;
                int endByte = (i == THREAD_COUNT - 1) ? contentLength - 1 : (startByte + partSize - 1);
                executor.execute(new DownloadTask(fileURL, saveFilePath, startByte, endByte, i));
            }

            executor.shutdown();
            // 创建 ProgressPrinter 对象
            ProgressPrinter progressPrinter = new ProgressPrinter(totalBytesRead, contentLength, startTime);
            // 使用 ProgressPrinter 对象打印进度
            while (!executor.awaitTermination(10, TimeUnit.MILLISECONDS)) {
                progressPrinter.print();
            }

            mergeParts(saveFilePath);
            progressPrinter.print(); // 最后一次更新进度
            return saveFilePath;
        } else {
            throw new IOException("没有文件可以下载. 服务器回复代码: " + responseCode);
        }
    }

    private void mergeParts(String filePath) throws IOException {
        try (FileOutputStream fos = new FileOutputStream(filePath);
             BufferedOutputStream mergingStream = new BufferedOutputStream(fos)) {
            for (int i = 0; i < Ev1FileDownloader.THREAD_COUNT; i++) {
                File partFile = new File(filePath + ".part" + i);
                try (FileInputStream fis = new FileInputStream(partFile);
                     BufferedInputStream in = new BufferedInputStream(fis)) {
                    byte[] buffer = new byte[4096];
                    int bytesRead;
                    while ((bytesRead = in.read(buffer)) != -1) {
                        mergingStream.write(buffer, 0, bytesRead);
                    }
                }
                partFile.delete();
            }
        }
    }

    private class DownloadTask implements Runnable {
        private final String fileURL;
        private final String saveFilePath;
        private final int startByte;
        private final int endByte;
        private final int partNumber;

        public DownloadTask(String fileURL, String saveFilePath, int startByte, int endByte, int partNumber) {
            this.fileURL = fileURL;
            this.saveFilePath = saveFilePath;
            this.startByte = startByte;
            this.endByte = endByte;
            this.partNumber = partNumber;
        }

        @Override
        public void run() {
            try {
                HttpURLConnection connection = (HttpURLConnection) new URL(fileURL).openConnection();
                connection.setRequestProperty("Range", "bytes=" + startByte + "-" + endByte);
                connection.connect();

                try (InputStream inputStream = connection.getInputStream();
                     RandomAccessFile partFile = new RandomAccessFile(saveFilePath + ".part" + partNumber, "rw")) {
                    partFile.seek(0);
                    byte[] buffer = new byte[4096];
                    int bytesRead;
                    while ((bytesRead = inputStream.read(buffer)) != -1) {
                        partFile.write(buffer, 0, bytesRead);
                        totalBytesRead.addAndGet(bytesRead);
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}