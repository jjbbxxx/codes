import java.io.*;
import java.net.Socket;

/**
 *
 */
public class BaseSocketTransmission {
    BaseSocketTransmission(){

    }

    /**
     * 为特定socket的outputStream输出特定文件。file参数的fileInputStream必须关闭，且函数会在使用后保持关闭
     * @param outputStream
     * @param file
     * @throws IOException
     */
    protected void sendFile(OutputStream outputStream, File file) throws IOException {
        // 读取文件内容并发送给服务器
        outputStream.write("START_FILE".getBytes());
        outputStream.flush();

        // 读取文件内容并发送给服务器
        FileInputStream fileInputStream = new FileInputStream(file);
        byte[] buffer = new byte[1024];
        int length;
        while ((length = fileInputStream.read(buffer)) != -1) {
            outputStream.write(buffer, 0, length);
        }
        fileInputStream.close();

        // 发送文件内容结束的标识
        outputStream.write("END_FILE".getBytes());
        outputStream.flush();
    }

    protected void getFile(InputStream inputStream,String pathName)throws IOException{
        byte[] buffer = new byte[1024];
        File file = new File(pathName);
        int length;
        boolean receivingFile = false;
        FileOutputStream fileOutputStream = null;
        while ((length = inputStream.read(buffer)) > 0) {
            String data = new String(buffer, 0, length);
            if (data.equals("START_FILE")) {
                receivingFile = true;
                continue;
            }
            if (data.equals("END_FILE")) {
                receivingFile = false;
                if (fileOutputStream != null) {
                    fileOutputStream.close();
                    fileOutputStream = null;
                }
                break;
            }
            if (receivingFile) {
                if (fileOutputStream == null) {
                    fileOutputStream = new FileOutputStream(file);
                }
                fileOutputStream.write(buffer, 0, length);
            }
        }
    }

    /**
     * 只在该方法提供的inputstream进行过测试：InputStream inputStream = socket.getInputStream();
     * @param inputStream
     * @return
     * @throws IOException
     */
    protected String getStringResponse(InputStream inputStream)throws IOException{
        InputStreamReader responseReader = new InputStreamReader(inputStream);
        BufferedReader responseBufferedReader = new BufferedReader(responseReader);
        String response = responseBufferedReader.readLine();

        // 关闭输入流 bufferedReader会关闭inputStreamReader，但是inputStream不会被关闭
        responseBufferedReader.close();
        return response;
    }

    protected void sendStringResponse(OutputStream outputStream,String response)throws IOException{
        outputStream.write(response.getBytes());
    }


}
