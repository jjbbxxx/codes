import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Ev1FileRenamerAndMover {

    private static final String BASE_DIR = "E:/张宇/"; // 基础目录
    private static final String DIR_PREFIX = "线代"; // 目录名前缀

    public static void renameAndMoveFile(String sourceFilePath) throws IOException {
        // 计算新文件名
        String newFileName = getNewFileName();
        // 构建新文件路径
        String destinationDir = BASE_DIR + DIR_PREFIX;
        Path newFilePath = Paths.get(destinationDir, newFileName);

        // 移动并重命名文件
        Path sourcePath = Paths.get(sourceFilePath);
        Files.move(sourcePath, newFilePath);
        System.out.println("文件已重命名并移动到: " + newFilePath);
    }

    private static String getNewFileName() {
        String destinationDir = BASE_DIR + DIR_PREFIX;
        File dir = new File(destinationDir);
        File[] files = dir.listFiles((d, name) -> name.endsWith(".flv"));
        int fileCount = (files != null) ? files.length : 0;
        // 新文件名：DIR_PREFIXn+1.flv，确保n为两位数
        return String.format("%s%02d.flv", DIR_PREFIX, fileCount + 1);
    }
}
}
