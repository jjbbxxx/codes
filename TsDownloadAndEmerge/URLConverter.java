public class URLConverter {

    public static String convertM3U8ToKeyURL(String m3u8URL) {
        if (m3u8URL == null || !m3u8URL.endsWith("index.m3u8")) {
            throw new IllegalArgumentException("Invalid M3U8 URL.");
        }
        return m3u8URL.replace("index.m3u8", "encrypt.key");
    }

    public static void main(String[] args) {
        String m3u8URL = "https://vmedia.mvjc.cn/media/file/video/4a/4a1ef3cfd3cc18f291278918c33301a6/index.m3u8";
        try {
            String keyURL = convertM3U8ToKeyURL(m3u8URL);
            System.out.println("Key URL: " + keyURL);
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
