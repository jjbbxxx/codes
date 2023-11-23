import java.io.*;
import java.net.*;

public class Server {
    static final int port = 1234;
    static final String ServerFileFolder = "ServerFiles/";

    public static void main(String[] args) {
        try {
            server();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void server() throws IOException {
        ServerSocket serverSocket = new ServerSocket(port);
        System.out.println("等待客户端连接...");
        Socket socket = serverSocket.accept();
        System.out.println("客户端已连接");

        // 接收客户端请求
        BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        String request = reader.readLine();

        // 根据客户端请求进行文件传输操作
        if (request.equals("upload")) {
            String fileName = reader.readLine();
            receiveFile(socket, fileName); // 上传文件
        } else if (request.equals("download")) {
            String fileName = reader.readLine();
            sendFile(socket, fileName);    // 下载文件
        }

        socket.close();
        serverSocket.close();
    }

    public static void receiveFile(Socket socket, String fileName) throws IOException {
        InputStream is = socket.getInputStream();
        FileOutputStream fos = new FileOutputStream(ServerFileFolder + fileName);

        byte[] buffer = new byte[1024];
        int bytesRead;
        while ((bytesRead = is.read(buffer)) != -1) {
            fos.write(buffer, 0, bytesRead);
        }

        System.out.println("文件上传完成");

        fos.close();

        // 发送上传完成的通知给客户端
        PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
        writer.println("上传完成");

        // 关闭输入流
        socket.shutdownInput();
    }

    public static void sendFile(Socket socket, String fileName) throws IOException {
        PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
        writer.println(fileName);

        File file = new File(ServerFileFolder + fileName);

        if (!file.exists()) {
            System.out.println("文件不存在");
            return;
        }

        FileInputStream fis = new FileInputStream(file);
        BufferedInputStream bis = new BufferedInputStream(fis);

        OutputStream os = socket.getOutputStream();

        byte[] buffer = new byte[1024];
        int bytesRead;
        while ((bytesRead = bis.read(buffer)) != -1) {
            os.write(buffer, 0, bytesRead);
        }

        System.out.println("文件下载完成");

        bis.close();
    }
}
