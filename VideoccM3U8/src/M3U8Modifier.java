import java.io.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class M3U8Modifier {

    public static String modifyM3U8File(String m3u8FilePath, String outputFilePath) throws IOException {
        File inputFile = new File(m3u8FilePath);
        File outputFile = new File(outputFilePath);
        StringBuilder contentBuilder = new StringBuilder();
        String keyUri = null;
        Pattern uriPattern = Pattern.compile("URI=\"(.*?)\"");
        Pattern segmentPattern = Pattern.compile("^(.*\\.ts)\\?.*$");

        // Read m3u8 file and modify URI and segment URLs
        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                Matcher uriMatcher = uriPattern.matcher(line);
                Matcher segmentMatcher = segmentPattern.matcher(line);
                if (uriMatcher.find()) {
                    keyUri = uriMatcher.group(1); // Extract URI
                    contentBuilder.append(line.replace(keyUri, "downloaded.key")).append(System.lineSeparator());
                } else if (segmentMatcher.find()) {
                    String segmentUrl = segmentMatcher.group(1); // Remove query parameters
                    contentBuilder.append(segmentUrl).append(System.lineSeparator());
                } else {
                    contentBuilder.append(line).append(System.lineSeparator());
                }
            }
        }

        // Write the modified content to a new file
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile))) {
            writer.write(contentBuilder.toString());
        }

        return keyUri;
    }
}
