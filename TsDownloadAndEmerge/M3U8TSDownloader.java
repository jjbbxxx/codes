import java.io.BufferedReader;
import java.io.BufferedInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.net.URL;

public class M3U8TSDownloader {

    public static void downloadTSFile(String fileURL, String savePath) throws IOException {
        URL url = new URL(fileURL);
        try (BufferedInputStream inputStream = new BufferedInputStream(url.openStream());
             FileOutputStream fileOutputStream = new FileOutputStream(savePath)) {
            byte[] dataBuffer = new byte[1024];
            int bytesRead;
            while ((bytesRead = inputStream.read(dataBuffer, 0, 1024)) != -1) {
                fileOutputStream.write(dataBuffer, 0, bytesRead);
            }
        } catch (IOException e) {
            throw e;
        }
    }

    public static void main(String[] args) {
        String m3u8FilePath = "path/to/your/local/index.m3u8"; // 您的M3U8本地文件路径
        String baseURL = "https://vmedia.mvjc.cn/media/file/video/4a/4a1ef3cfd3cc18f291278918c33301a6/";

        try (BufferedReader br = new BufferedReader(new FileReader(m3u8FilePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                if (line.endsWith(".ts")) {
                    String tsFileName = line;
                    String fileURL = baseURL + tsFileName;
                    String savePath = "downloaded_" + tsFileName;

                    try {
                        downloadTSFile(fileURL, savePath);
                        System.out.println(tsFileName + " downloaded successfully.");
                    } catch (IOException e) {
                        System.out.println("Error downloading " + tsFileName + ": " + e.getMessage());
                    }
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading M3U8 file: " + e.getMessage());
        }
    }
}
