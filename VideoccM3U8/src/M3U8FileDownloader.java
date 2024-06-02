import java.io.BufferedInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;

public class M3U8FileDownloader {

    public static void downloadM3U8File(String fileURL, String savePath) throws IOException {
        // 设置系统属性以使用系统代理配置
        System.setProperty("java.net.useSystemProxies", "true");

        URL url = new URL(fileURL);
        HttpURLConnection connection = (HttpURLConnection) url.openConnection();

        connection.setConnectTimeout(10000);
        connection.setReadTimeout(10000);

        try (InputStream inputStream = new BufferedInputStream(connection.getInputStream());
             FileOutputStream outputStream = new FileOutputStream(savePath)) {
            byte[] buffer = new byte[1024];
            int bytesRead;
            while ((bytesRead = inputStream.read(buffer)) != -1) {
                outputStream.write(buffer, 0, bytesRead);
            }
        }
    }
}
