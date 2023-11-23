import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    static final String HostIP = "localhost";
    static final int port = 1234;
    static final String ClientFileFolder = "ClientFiles/";
    static Socket socket;

    public static void main(String[] args) {
        try {
            socket = new Socket(HostIP, port);
            System.out.println("连接服务器成功");

            menu();

            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void menu() {
        try {
            boolean check = true;
            String typeString = null;
            System.out.print("请选择：1.上传文件 2.下载文件\t");
            Scanner scan = new Scanner(System.in);
            int type = scan.nextInt();
            if (type == 1) {
                typeString = "upload";
            } else if (type == 2) {
                typeString = "download";
            } else {
                System.out.println("输入有误！");
                return;
            }

            // 发送请求类型给服务器
            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
            writer.println(typeString);

            // 接收用户输入的文件名
            Scanner scanner = new Scanner(System.in);
            System.out.print("请输入文件名(包括后缀名)：");
            String fileName = scanner.nextLine();

            // 发送文件名给服务器
            writer.println(fileName);

            // 根据服务器的响应进行相应操作
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String response = reader.readLine();
            if (response.equals("upload")) {
                sendFile(fileName);    // 上传文件
            } else if (response.equals("download")) {
                receiveFile(fileName); // 下载文件
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void sendFile(String fileName) {
        try {
            File file = new File(ClientFileFolder + fileName);

            if (!file.exists()) {
                System.out.println("文件不存在");
                return;
            }

            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
            writer.println("upload");

            OutputStream os = socket.getOutputStream();

            FileInputStream fis = new FileInputStream(file);
            BufferedInputStream bis = new BufferedInputStream(fis);

            byte[] buffer = new byte[1024];
            int bytesRead;
            while ((bytesRead = bis.read(buffer)) != -1) {
                os.write(buffer, 0, bytesRead);
            }

            System.out.println("文件上传完成");

            bis.close();
            os.flush(); // 刷新输出流

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void receiveFile(String fileName) {
        try {
            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
            writer.println("download");

            OutputStream os = socket.getOutputStream();

            InputStream is = socket.getInputStream();
            FileOutputStream fos = new FileOutputStream(ClientFileFolder + fileName);
            BufferedOutputStream bos = new BufferedOutputStream(fos);

            byte[] buffer = new byte[1024];
            int bytesRead;
            while ((bytesRead = is.read(buffer)) != -1) {
                bos.write(buffer, 0, bytesRead);
            }

            System.out.println("文件下载完成");

            bos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
