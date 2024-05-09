import java.io.File;
import java.io.IOException;

public class ClearDirectory {

    public static void main(String[] args) {
        String directoryPath = "C:\\Users\\asus\\Downloads\\TSDownload\\cache";
        File directory = new File(directoryPath);

        try {
            deleteDirectoryContents(directory);
            System.out.println("Directory has been cleared.");
        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }

    private static void deleteDirectoryContents(File dir) throws IOException {
        File[] allContents = dir.listFiles();
        if (allContents != null) {
            for (File file : allContents) {
                deleteFile(file);
            }
        }
    }

    private static void deleteFile(File file) throws IOException {
        if (file.isDirectory()) {
            deleteDirectoryContents(file);
        }
        if (!file.delete()) {
            throw new IOException("Failed to delete " + file);
        }
    }
}
