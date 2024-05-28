import java.io.IOException;

public class Ev1Decoder {

    private static final String DECODER_PATH = "E:/张宇/cache/ev1_decode.exe"; // ev1_decode.exe 的路径

    public void decode(String filePath) throws IOException, InterruptedException {
        // 构建命令行命令
        String command = DECODER_PATH + " " + filePath;

        // 创建进程来执行命令
        Process process = Runtime.getRuntime().exec(command);

        // 等待进程完成
        int exitCode = process.waitFor();

        if (exitCode == 0) {
            System.out.println("解码成功: " + filePath);
            // 构建解码后的文件路径
            String decodedFilePath = filePath + ".flv";
            // 重命名并移动文件
            Ev1FileRenamerAndMover.renameAndMoveFile(decodedFilePath);
        } else {
            System.out.println("解码失败，错误代码: " + exitCode);
        }
    }
}
