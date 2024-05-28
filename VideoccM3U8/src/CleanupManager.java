import java.io.File;
import java.io.IOException;

public class CleanupManager {

    public static void cleanUp(String directoryPath) {
        File directory = new File(directoryPath);
        if (!directory.exists()) {
            System.out.println("Directory does not exist: " + directoryPath);
            return;
        }

        File[] files = directory.listFiles();
        if (files == null) {
            System.out.println("Failed to list files in directory: " + directoryPath);
            return;
        }

        for (File file : files) {
            if (file.isFile() && (file.getName().endsWith(".key") || file.getName().endsWith(".m3u8") || file.getName().endsWith(".ts"))) {
                if (file.delete()) {
                } else {
                    System.out.println("Failed to delete file: " + file.getName());
                }
            }
        }
    }
}
