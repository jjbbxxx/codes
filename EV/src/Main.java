import java.io.IOException;
import java.util.Scanner;

public class Main {
    private static final String SAVE_DIR = "E:/张宇/cache"; // 固定的下载目录

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入要下载的文件URL:");
        String fileURL = scanner.nextLine();

        try {
            Ev1FileDownloader downloader = new Ev1FileDownloader();
            String downloadedFilePath = downloader.downloadFile(fileURL, SAVE_DIR);
            System.out.println("下载完成");

            Ev1Decoder decoder = new Ev1Decoder();
            decoder.decode(downloadedFilePath);
            System.out.println("解码完成");
        } catch (IOException | InterruptedException ex) {
            System.out.println("操作失败: " + ex.getMessage());
            ex.printStackTrace();
        }
    }
}
