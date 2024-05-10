import java.io.File;

public class FileRenamer {
    public static void rename() {
        // 指定要重命名的文件的路径
        String originalFilePath = "C:\\Users\\asus\\Downloads\\TSDownload\\cache\\index.m3u8";
        String newFilePath = "C:\\Users\\asus\\Downloads\\TSDownload\\cache\\index0.m3u8";

        // 创建File对象
        File originalFile = new File(originalFilePath);
        File newFile = new File(newFilePath);

        // 执行重命名操作
        boolean renamed = originalFile.renameTo(newFile);

        if (renamed) {
            System.out.println("File renamed successfully!");
        } else {
            System.out.println("Failed to rename the file.");
        }
    }
}
