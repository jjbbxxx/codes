import java.io.*;
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
        }
    }

    public static void down(String m3u8URL,int method) {
        if (method ==0) {
            String m3u8FilePath = "C:\\Users\\asus\\Downloads\\TSDownload\\cache\\index.m3u8"; // 您的M3U8本地文件路径
            String baseURL = m3u8URL.substring(0, m3u8URL.lastIndexOf('/') + 1);

            try (BufferedReader br = new BufferedReader(new FileReader(m3u8FilePath))) {
                String line;
                while ((line = br.readLine()) != null) {
                    if (line.endsWith(".ts")) {
                        String fileURL = baseURL + line;
                        String savePath = "C:\\Users\\asus\\Downloads\\TSDownload\\cache\\" + line;

                        try {
                            downloadTSFile(fileURL, savePath);
                            System.out.println(line + " downloaded successfully.");
                        } catch (IOException e) {
                            System.out.println("Error downloading " + line + ": " + e.getMessage());
                        }
                    }
                }
            } catch (IOException e) {
                System.out.println("Error reading M3U8 file: " + e.getMessage());
            }
        }
        else if(method==1){
            String baseURL = m3u8URL.substring(0, m3u8URL.lastIndexOf('/') + 1);
                String line;
                int x=1;
                while(true) {
                    String s = String.format("%03d", x);
                    line = "index"+ s +".ts";
                        String fileURL = baseURL + line ;
                        String savePath = "C:\\Users\\asus\\Downloads\\TSDownload\\cache\\" + line;

                        try {
                            downloadTSFile(fileURL, savePath);
                            System.out.println(line + " downloaded successfully.");
                        } catch (IOException e) {
                            System.out.println("End downloading");
                            return;
                        }
                        x++;
                    }
                }
            }



}

