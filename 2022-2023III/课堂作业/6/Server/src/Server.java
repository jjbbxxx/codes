import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    private static final String SERVER_FILES_PATH = "ServerFiles/";

    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(8888);
            while (true) {
                Socket socket = serverSocket.accept();
                Thread clientHandler = new Thread(new ClientHandler(socket));
                clientHandler.start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static class ClientHandler implements Runnable {
        private Socket clientSocket;

        public ClientHandler(Socket socket) {
            this.clientSocket = socket;
        }

        @Override
        public void run() {
            try {
                InputStream inputStream = clientSocket.getInputStream();
                OutputStream outputStream = clientSocket.getOutputStream();

                byte[] buffer = new byte[1024];
                int length = inputStream.read(buffer);

                String fileName = new String(buffer, 1, length);
                File file = new File(SERVER_FILES_PATH + fileName);

                int choose=inputStream.read(buffer,0,1);

                System.out.println(choose);
                if(choose==1){

                }
                else if(choose==2){
                    if (file.exists()) {
                        // 文件已存在，拒绝上传
                        String response = "文件已存在，上传被拒绝。";
                        outputStream.write(response.getBytes());
                    } else {
                        // 文件不存在，进行上传操作
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

                        String response = "文件上传成功。";
                        outputStream.write(response.getBytes());
                    }
                }

                outputStream.flush();
                inputStream.close();
                outputStream.close();
                clientSocket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
}