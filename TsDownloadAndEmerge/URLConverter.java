public class URLConverter {

    public static String convertM3U8ToKeyURL(String m3u8URL) {
        if (m3u8URL.endsWith("index.m3u8"))
        return m3u8URL.replace("index.m3u8", "encrypt.key");
        else
            return m3u8URL.replace("preview.m3u8", "encrypt.key");
    }

    public static String convertM3U8ToKeyURL1(String m3u8URL) {
        if (m3u8URL.endsWith("index.m3u8"))
            return m3u8URL.replace("index.m3u8", "enc.key");
        else
            return m3u8URL.replace("preview.m3u8", "enc.key");
    }

    public static String convertM3U8ToKeyURL2(String m3u8URL) {
        if (m3u8URL.endsWith("index.m3u8"))
            return m3u8URL.replace("index.m3u8", "enc.info");
        else
            return m3u8URL.replace("preview.m3u8", "enc.info");
    }

    public static String convertPreviewToIndex(String url) {
        return url.replace("preview.m3u8", "index.m3u8");
    }
}
