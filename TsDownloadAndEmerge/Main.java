import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        ClearDirectory.main(null);
        System.out.print("请输入m3u8 URL:");
        Scanner scan = new Scanner(System.in);
        String m3u8URL = scan.nextLine().trim();
        int method=0;
        if (m3u8URL.contains("preview")) method=1;
        String keyURL = null;
        String keyURL1 = null;
        String keyURL2 = null;
        String m3u8savePath = "C:\\Users\\asus\\Downloads\\TSDownload\\cache\\index.m3u8"; // 您想要保存文件的路径和文件名
        String keySavePath = "C:\\Users\\asus\\Downloads\\TSDownload\\cache\\encrypt.key";
        String keySavePath1 = "C:\\Users\\asus\\Downloads\\TSDownload\\cache\\enc.key";
        String keySavePath2 = "C:\\Users\\asus\\Downloads\\TSDownload\\cache\\enc.info";
        try {
            keyURL = URLConverter.convertM3U8ToKeyURL(m3u8URL);
            keyURL1 = URLConverter.convertM3U8ToKeyURL1(m3u8URL);
            keyURL2 = URLConverter.convertM3U8ToKeyURL2(m3u8URL);
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        }

        try {
            FileDownloader.downloadFile(m3u8URL, m3u8savePath);
            System.out.println("m3u8 File downloaded successfully.");
        } catch (IOException e) {
            System.out.println("Error downloading file: " + e.getMessage());
        }

        try {
            FileDownloader.downloadFile(keyURL, keySavePath);
            System.out.println("key File downloaded successfully.");
        } catch (IOException e) {
            System.out.println("Error downloading file: " + e.getMessage());
            try {
                FileDownloader.downloadFile(keyURL1, keySavePath1);
                System.out.println("key File1 downloaded successfully.");
            } catch (IOException e1) {
                System.out.println("Error downloading file: " + e1.getMessage());
                try {
                    FileDownloader.downloadFile(keyURL2, keySavePath2);
                    System.out.println("key File2 downloaded successfully.");
                } catch (IOException e2) {
                    System.out.println("Error downloading file: " + e2.getMessage());
                }
            }
        }
        M3U8Modifier.main(null);
        M3U8TSDownloader.down(m3u8URL,method);
        FFmpegCommandExecutor.main(null);
    }


}