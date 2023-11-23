import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static interface_.MusicDao.executeQueryForList;

/**
 * @author Ninemerlin
 */
public class ControlTask extends BaseSocketTransmission{
    ArrayList<DataTask> dataTasks;
    HashMap<Integer,Thread>controlSockets=new HashMap<>();
    SocketCommand command=new SocketCommand();
    final static int LISTEN_PORT=4413;

    /**
     * 考虑通过另一流程控制线程跳出该方法的循环
     */
    ControlTask(){
        try {
            while (true) {
                //为每个对listenPort的连接提供一个controlport，随后销毁线程重新监听
                ServerSocket listenSocket = new ServerSocket(LISTEN_PORT);
                Socket socket = listenSocket.accept();
                Thread listenSocketHandler = new Thread(new ListenSocketHandler(socket,controlSockets));
                listenSocketHandler.start();

                ServerSocket controlSocket = new ServerSocket(ListenSocketHandler.tempControlPort);
                Socket conSocket=controlSocket.accept();
                Thread controlSocketHandler = new Thread(new CommandHandler(conSocket));
                controlSockets.put(ListenSocketHandler.tempControlPort,controlSocketHandler);

                socket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    };

    private static class CommandHandler extends BaseSocketTransmission implements Runnable {
        private Socket clientSocket;

        SocketCommand command;
        String pathName="./command";
        public CommandHandler(Socket socket) {
            this.clientSocket = socket;
        }

        @Override
        public void run() {
            try {
                InputStream inputStream = clientSocket.getInputStream();
                OutputStream outputStream = clientSocket.getOutputStream();

                getFile(inputStream,pathName);
                deserializeCommandObject(pathName);
                switch (command.getCommand()){
                    case "download" -> {
                         for(Map.Entry<String,String> entry:command.getOptionAndValue()){
                             String musicName = entry.getKey();
                             String downloadPath = entry.getValue();


                             // 构建下载文件的请求命令
                             SocketCommand downloadCommand = new SocketCommand();
                             downloadCommand.setCommand("download");
                             downloadCommand.addOptionAndValue("name", musicName);

                             // 将请求命令发送给服务器
                             sendStringResponse(outputStream, "download"); // 发送下载命令
                             sendStringResponse(outputStream, musicName); // 发送音乐名称

                             // 接收文件数据并保存到本地
                             getFile(inputStream, downloadPath);

                             // 关闭连接和流
                             clientSocket.close();
                             inputStream.close();
                             outputStream.close();
                        }

                    }
                    case"upload"->{
                        for (Map.Entry<String, String> entry : command.getOptionAndValue()) {
                            String filePath = entry.getKey();

                            // 创建Socket连接，并获取输入流和输出流


                            // 构建上传文件的请求命令
                            SocketCommand uploadCommand = new SocketCommand();
                            uploadCommand.setCommand("upload");
                            uploadCommand.addOptionAndValue("filePath", filePath);

                            // 将请求命令发送给服务器
                            sendStringResponse(outputStream, "upload"); // 发送上传命令
                            sendStringResponse(outputStream, filePath); // 发送文件路径

                            // 发送文件数据给服务器
                            File file = new File(filePath);
                            sendFile(outputStream, file);

                            // 关闭连接和流
                            clientSocket.close();
                            inputStream.close();
                            outputStream.close();
                        }

                    }
                    case"check"->{
                        for (Map.Entry<String, String> entry : command.getOptionAndValue()) {
                            String tableName = entry.getKey();
                            String condition = entry.getValue();

                            try {
                                // 构建查询语句
                                String sql = "SELECT * FROM " + tableName + " WHERE " + condition;

                                // 执行查询
                                List<Map<String, Object>> result = MusicMysqlImpleDao.executeQueryForList(sql);

                                // 将查询结果发送给客户端
                                ObjectOutputStream objectOutputStream = new ObjectOutputStream(outputStream);
                                objectOutputStream.writeObject(result);
                                objectOutputStream.flush();
                            } catch (SQLException | ClassNotFoundException | IOException e) {
                                e.printStackTrace();
                            } catch (Exception e) {
                                throw new RuntimeException(e);
                            }
                        }

                        // 关闭连接和流
                        clientSocket.close();
                        inputStream.close();
                        outputStream.close();
                    }
                    case "score" -> {
                        for (Map.Entry<String, String> entry : command.getOptionAndValue()) {
                            String musicId = entry.getKey();
                            int score = Integer.parseInt(entry.getValue());

                            try {
                                // 调用 score 方法进行音乐评分
                                int count = MusicMysqlImpleDao.score(musicId, score);

                                // 将更新的行数发送给客户端
                                sendStringResponse(outputStream, String.valueOf(count));
                            } catch (SQLException | ClassNotFoundException | IOException e) {
                                e.printStackTrace();
                            } catch (Exception e) {
                                throw new RuntimeException(e);
                            }
                        }

                        // 关闭连接和流
                        clientSocket.close();
                        inputStream.close();
                        outputStream.close();
                    }
                    default -> {}
                }

//                    String response = "文件上传成功。";
//                    outputStream.write(response.getBytes());


//                outputStream.flush();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        void serializeCommandObject(){
            try (FileOutputStream fileOut = new FileOutputStream("command");
                 ObjectOutputStream out = new ObjectOutputStream(fileOut)) {
                out.writeObject(command);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        void deserializeCommandObject(String filePath){
            try (FileInputStream fileIn = new FileInputStream(filePath);
                 ObjectInputStream in = new ObjectInputStream(fileIn)) {
                command = (SocketCommand) in.readObject();
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        }


    }

    private static class ListenSocketHandler extends BaseSocketTransmission implements Runnable{
        private Socket listenSocket;
        HashMap<Integer,Thread>controlSockets;
        static int tempControlPort=5000;
        public ListenSocketHandler(Socket listenSocket,HashMap<Integer,Thread>controlSockets){
            this.listenSocket=listenSocket;
            this.controlSockets=controlSockets;
        }

        /**
         * 返回一个当前可以用于创建线程的端口
         * @return int
         */
        int getTempControlPort(){
            tempControlPort=(tempControlPort+1)%10000;
            if(tempControlPort==0){
                tempControlPort+=5000;
            }
            while(controlSockets.get(tempControlPort).isAlive()){
                tempControlPort++;
            }
            return tempControlPort;
        }

        @Override
        public void run(){
            try{
                OutputStream outputStream=listenSocket.getOutputStream();
                sendStringResponse(outputStream,Integer.toString(getTempControlPort()));
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }




}
