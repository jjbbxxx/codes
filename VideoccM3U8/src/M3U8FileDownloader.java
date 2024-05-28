import java.io.*;
import java.net.URL;

public class M3U8FileDownloader {

    public static void downloadM3U8File(String m3u8Url, String outputFilePath) throws IOException {
        URL url = new URL(m3u8Url);
        try (BufferedInputStream in = new BufferedInputStream(url.openStream());
             FileOutputStream fileOutputStream = new FileOutputStream(outputFilePath)) {
            byte dataBuffer[] = new byte[1024];
            int bytesRead;
            while ((bytesRead = in.read(dataBuffer, 0, 1024)) != -1) {
                fileOutputStream.write(dataBuffer, 0, bytesRead);
            }
        }
    }
}
