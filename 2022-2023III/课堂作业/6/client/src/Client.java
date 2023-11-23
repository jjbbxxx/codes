import java.io.*;
import java.net.Socket;

public class Client {
    private static final String SERVER_ADDRESS = "localhost";
    private static final String CLIENT_FILES_PATH = "ClientFiles/";

    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("请选择上传还是下载文件：");
            System.out.println("1.上传文件");
            System.out.println("2.下载文件");
            int choice = Integer.parseInt(reader.readLine());
            if (choice == 1) {
                System.out.println("请输入要上传的文件名：");
                String fileName = reader.readLine();
                File file = new File(CLIENT_FILES_PATH + fileName);
                if (!file.exists()) {
                    System.out.println("文件不存在！");
                    return;
                }
                Socket socket = new Socket(SERVER_ADDRESS, 8888);
                OutputStream outputStream = socket.getOutputStream();
                InputStream inputStream = socket.getInputStream();

                // 发送文件名和文件长度信息给服务器
                outputStream.write(fileName.getBytes());
                Thread.sleep(500);
                outputStream.flush();
                long fileLength = file.length();
                outputStream.write(String.valueOf(fileLength).getBytes());
                outputStream.flush();

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

                // 关闭输出流，通知服务器端数据传输完成
                socket.shutdownOutput();

                // 接收服务器端的响应
                InputStreamReader responseReader = new InputStreamReader(inputStream);
                BufferedReader responseBufferedReader = new BufferedReader(responseReader);
                String response = responseBufferedReader.readLine();
                System.out.println(response);

                // 关闭输入流和套接字
                responseBufferedReader.close();
                inputStream.close();
                socket.close();
            } else if (choice == 2) {
                System.out.println("请输入要下载的文件名：");
                String fileName = reader.readLine();
                Socket socket = new Socket(SERVER_ADDRESS, 8888);
                OutputStream choose = socket.getOutputStream();
                OutputStream outputStream = socket.getOutputStream();
                InputStream inputStream = socket.getInputStream();
                choose.write(2);
                outputStream.write(fileName.getBytes());
                outputStream.flush();
                byte[] buffer = new byte[1024];
                int length;
                File file = new File(CLIENT_FILES_PATH + fileName);
                FileOutputStream fileOutputStream = new FileOutputStream(file);
                while ((length = inputStream.read(buffer)) > 0) {
                    fileOutputStream.write(buffer, 0, length);
                    if (length < buffer.length) {
                        break;
                    }
                }
                fileOutputStream.flush();
                fileOutputStream.close();
                inputStream.close();
                outputStream.close();
                socket.close();
            } else {
                System.out.println("输入错误！");
            }
        } catch (IOException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}