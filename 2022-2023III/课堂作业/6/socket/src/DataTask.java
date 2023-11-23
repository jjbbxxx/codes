import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * 服务端数据传输类。
 * constructor: port传输端口    filePath本地存储位置     isUpload指定为上传，否则下载
 */
public class DataTask extends BaseSocketTransmission implements Runnable{
    final int port;
    String filePath;
    boolean isUpload;
    DataTask(int port,String filePath,boolean isUpload){
        this.filePath=filePath;
        this.port=port;
        this.isUpload=isUpload;
    }

    @Override
    public void run(){
        try {
            ServerSocket serverSocket = new ServerSocket(port);
            Socket socket = serverSocket.accept();
            if(isUpload){
                InputStream inputStream=socket.getInputStream();
                getFile(inputStream,filePath);
                inputStream.close();
                socket.close();
            }else{
                OutputStream outputStream=socket.getOutputStream();
                File file= new File(filePath);
                sendFile(outputStream,file);
                outputStream.close();
                socket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
