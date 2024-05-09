import java.io.BufferedInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.URL;

public class FileDownloader {

    public static void downloadFile(String fileURL, String savePath) throws IOException {
        URL url = new URL(fileURL);
        try (BufferedInputStream inputStream = new BufferedInputStream(url.openStream());
             FileOutputStream fileOutputStream = new FileOutputStream(savePath)) {
            byte[] dataBuffer = new byte[1024];
            int bytesRead;
            while ((bytesRead = inputStream.read(dataBuffer, 0, 1024)) != -1) {
                fileOutputStream.write(dataBuffer, 0, bytesRead);
            }
        } catch (IOException e) {
            // Handle exceptions
            throw e;
        }
    }

    public static void main(String[] args) {
        String fileURL = "http://example.com/file.zip"; // 替换为您想要下载的文件的URL
        String savePath = "downloaded_file.zip"; // 您想要保存文件的路径和文件名

        try {
            downloadFile(fileURL, savePath);
            System.out.println("File downloaded successfully.");
        } catch (IOException e) {
            System.out.println("Error downloading file: " + e.getMessage());
        }
    }
}
