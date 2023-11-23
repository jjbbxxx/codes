import org.apache.commons.cli.*;

import java.io.*;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

import static java.lang.System.exit;

public class Client extends BaseSocketTransmission {
    private static final String SERVER_ADDRESS = "localhost";
    private static final int SERVER_PORT = 4413;
    private static final String CLIENT_FILES_PATH = "ClientFiles/";
    private static final String JAR_PATH="../jar";
    private static final char CATALOGUE_NAME_END='/';


    /**
     * <p>需要重构该变量（optionList）为HashMap<String,Options></p>
     * String为命令名称，Options为对于的options
     * 并一并更改addOptions系列函数和parseCommand中的help分支
     */
    ArrayList<Options> optionList;
    CommandLine cmd;
    CommandLineParser parser = new DefaultParser();
    HelpFormatter helper = new HelpFormatter();
    SocketCommand command;
    String commandPath="./command";
    Client(){
//        try {
//            JarLoader.loadAllJarFromAbsolute(JAR_PATH);
//        } catch (NoSuchMethodException e) {
//            throw new RuntimeException(e);
//        } catch (InvocationTargetException e) {
//            throw new RuntimeException(e);
//        } catch (IllegalAccessException e) {
//            throw new RuntimeException(e);
//        } catch (IOException e) {
//            throw new RuntimeException(e);
//        }

        addDownloadOptions();
        addCheckOptions();
        addUploadOptions();
        addScore();
        addHelp();
        addExit();
    }

    /**
     * <p>添加下载选项</p>
     * <p>-n 指定要下载的音乐名     -p指定下载的音乐的保存位置</p>
     */
    void addDownloadOptions(){
        optionList.add(new Options());
        int index=0;

        Option downloadNameOption = Option.builder("n")
                .longOpt("name")
                .argName("name")
                .hasArg()
                .required(true)
                .desc("download the music have the name")
                .build();

        Option downloadPathOption = Option.builder("p")
                .longOpt("path")
                .argName("path")
                .hasArg()
                .required(true)
                .desc("download the music to the path")
                .build();

        optionList.get(index).addOption(downloadNameOption);
        optionList.get(index).addOption(downloadPathOption);
    }

    /**
     * <p>添加查询选项，命令check</p>
     * <p>-n 指定要查询的音乐名称    -p指定要查询的演奏者名字   -t指定要查询的音乐类型</p>
     */
    void addCheckOptions(){
        optionList.add(new Options());
        int index=1;

        Option checkMusicName=Option.builder("n")
                .longOpt("musicName")
                .argName("musicName")
                .hasArg()
                .desc("check through musicName")
                .build();

        Option checkPlayerName=Option.builder("p")
                .longOpt("playerName")
                .argName("playerName")
                .hasArg()
                .desc("check through playerName")
                .build();

        Option checkMusicType=Option.builder("t")
                .longOpt("musicType")
                .argName("musicType")
                .hasArg()
                .desc("check through musicType")
                .build();

        optionList.get(index).addOption(checkMusicName);
        optionList.get(index).addOption(checkPlayerName);
        optionList.get(index).addOption(checkMusicType);
    }

    /**
     * <p>添加上传音乐选项</p>
     * <p>-n 指定音乐的路径   -p指定发布时间    -t指定音乐类型    -y指定演奏者名字   -r指定推荐者的名字</p>
     */
    void addUploadOptions(){
        optionList.add(new Options());
        int index=2;

        Option uploadPathAndName=Option.builder("n")
                .longOpt("Path&Name")
                .argName("Path&Name")
                .hasArg()
                .required(true)
                .desc("point the fullPath of the music, like C:/download/music.mp3 or the relative path")
                .build();

        Option uploadPublishTime=Option.builder("p")
                .longOpt("publishTime")
                .argName("publishTime")
                .hasArg()
                .desc("point the music's publishTime")
                .build();

        Option uploadMusicType=Option.builder("t")
                .longOpt("musicType")
                .argName("musicType")
                .hasArg()
                .desc("point the music's musicType")
                .build();

        Option uploadPlayerName=Option.builder("y")
                .longOpt("playerName")
                .argName("playerName")
                .hasArg()
                .desc("point the music's player's name")
                .build();

        Option uploadRecommender=Option.builder("r")
                .longOpt("recommender")
                .argName("recommender")
                .hasArg()
                .desc("point your name as the recommender")
                .build();

        optionList.get(index).addOption(uploadPathAndName);
        optionList.get(index).addOption(uploadPublishTime);
        optionList.get(index).addOption(uploadMusicType);
        optionList.get(index).addOption(uploadPlayerName);
        optionList.get(index).addOption(uploadRecommender);
    }

    /**
     * <p>添加打分选项</p>
     * -i指定要打分的音乐   -s指定分数
     */
    void addScore(){
        optionList.add(new Options());
        int index=3;

        Option musicId=Option.builder("i")
                .longOpt("id")
                .argName("musicId")
                .hasArg()
                .required(true)
                .desc("point the music's id, although you shouldn't know it")
                .build();

        Option scoreNum=Option.builder("s")
                .longOpt("score")
                .argName("score")
                .hasArg()
                .required(true)
                .desc("point the score you want to give for the music")
                .build();

        optionList.get(index).addOption(musicId);
        optionList.get(index).addOption(scoreNum);
    }

    /**
     * 添加帮助选项
     *
     */
    void addHelp(){
        optionList.add(new Options());
        int index=4;

    }

    void addExit(){
        optionList.add(new Options());
        int index=5;
    }

    /**
     * 解析输入的命令，
     * @param args
     */
    boolean parseCommand(String[] args,InputStream inputStream,OutputStream outputStream)throws IOException,InterruptedException{
        try {
            if (args.length > 0 ) {
                switch(args[0]){
                    case "exit" -> {return false;}
                    case "help" -> {
                        HelpFormatter helpFormatter=new HelpFormatter();
                        helpFormatter.printHelp("download",optionList.get(0));
                        helpFormatter.printHelp("check",optionList.get(1));
                        helpFormatter.printHelp("upload",optionList.get(2));
                        helpFormatter.printHelp("score",optionList.get(3));
                    }
                    case "download" ->{
                        // 解析命令行参数
                        CommandLine cmd = parser.parse(optionList.get(0), args);
                        // 获取命令行参数列表
                        String[] remainingArgs = cmd.getArgs();
                        //告知服务器将要下载
                        command.setCommand("download");
                        if(remainingArgs.length>0){
                            for(String arg:remainingArgs){
                                command.addOptionAndValue(arg, cmd.getOptionValue(arg));
                            }
                        }else{
                            return true;
                        }
                        serializeCommandObject();
                        sendFile(outputStream,new File(commandPath));

                        Thread.sleep(300);
                        //接收数据传输端口，是否会丢失需要测试
                        String dataPort=getStringResponse(inputStream);
                        //创建新的端口上的对应线程
                        try{
                            Thread transmissionHandler = new Thread(new DownloadHandler(SERVER_ADDRESS,Integer.parseInt(dataPort), cmd.getOptionValue("p")));
                            transmissionHandler.start();
                        }catch(IOException e){
                            exit(1);
                        }
                    }
                    case "check" ->{
                        // 解析命令行参数
                        CommandLine cmd = parser.parse(optionList.get(1), args);
                        // 获取命令行参数列表
                        String[] remainingArgs = cmd.getArgs();
                        //告知服务器将要检查
                        command.setCommand("check");
                        if(remainingArgs.length>0){
                            for(String arg:remainingArgs){
                                command.addOptionAndValue(arg, cmd.getOptionValue(arg));
                            }
                        }else{
                            return true;
                        }
                        serializeCommandObject();
                        sendFile(outputStream,new File(commandPath));

                        Thread.sleep(300);
                        //接收传输端口，是否会丢失需要测试
                        String dataPort=getStringResponse(inputStream);

                        //创建新的端口上的对应线程
                        Thread transmissionHandler = new Thread(new CheckHandler(SERVER_ADDRESS,Integer.parseInt(dataPort)));
                        transmissionHandler.start();
                    }
                    case "upload" ->{
                        /**
                         * 与下载一样，发送控制信息，等待新的端口，连接并上传。
                         */
                        CommandLine cmd = parser.parse(optionList.get(2), args);
                        // 获取命令行参数列表
                        String[] remainingArgs = cmd.getArgs();
                        //告知服务器要上传
                        command.setCommand("upload");
                        if(remainingArgs.length>0){
                            for(String arg:remainingArgs){
                                command.addOptionAndValue(arg, cmd.getOptionValue(arg));
                            }
                        }else{
                            return true;
                        }
                        serializeCommandObject();
                        sendFile(outputStream,new File(commandPath));

                        Thread.sleep(300);
                        //接收传输端口，是否会丢失需要测试
                        String dataPort=getStringResponse(inputStream);

                        //创建新的端口上的对应线程
                        try{
                            Thread transmissionHandler = new Thread(new UploadHandler(SERVER_ADDRESS,Integer.parseInt(dataPort), cmd.getOptionValue("p")));
                            transmissionHandler.start();
                        }catch(IOException e){
                            exit(1);
                        }
                    }
                    case "score" ->{
                        /**
                         * 打分直接通过control端口就可以了
                         */
                        CommandLine cmd = parser.parse(optionList.get(3), args);
                        // 获取命令行参数列表
                        String[] remainingArgs = cmd.getArgs();
                        //告知服务器要打分
                        command.setCommand("upload");
                        if(remainingArgs.length>0){
                            for(String arg:remainingArgs){
                                command.addOptionAndValue(arg, cmd.getOptionValue(arg));
                            }
                        }else{
                            return true;
                        }
                        serializeCommandObject();
                        sendFile(outputStream,new File(commandPath));
                    }
                    default -> {
                        System.out.println("未知命令: " + args[0]);
                        /**
                         * 应调用help函数
                         */
                    }
                }
            }
        } catch (ParseException e) {
            System.out.println(e.getMessage());
            /**
             * 调用help函数
             */
            exit(1);
        }
        return true;
    }

    /**
     * DownloadHandler constructor's parameter "path" must end with "/"
     */
    class DownloadHandler extends BaseSocketTransmission implements Runnable{
        Socket socket;
        String path;
        DownloadHandler(String serverAddress,int port,String path)throws IOException{
            socket = new Socket(serverAddress, port);
            try {
                if (path.charAt(path.length() - 1) != CATALOGUE_NAME_END) {
                    throw new IOException();
                } else {
                    this.path = path;
                }
            } catch (IOException e) {
                try {
                    socket.close();
                } catch (IOException ex) {
                    // 处理关闭 socket 时可能抛出的异常
                    ex.printStackTrace();
                }
                throw e;
            }
        }

        @Override
        public void run(){
            try {
                InputStream inputStream = socket.getInputStream();
                getFile(inputStream,path);
                inputStream.close();
                socket.close();

                PrivateProtocolFile tempFile=deserializeFileObject(path);
                if(tempFile!=null){

                }

            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    class CheckHandler extends BaseSocketTransmission implements  Runnable{
        Socket socket;
        CheckHandler(String serverAddress,int port){
            try {
                socket=new Socket(serverAddress,port);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        @Override
        public void run(){
            try {
                InputStream inputStream= socket.getInputStream();
                String temp=getStringResponse(inputStream);
                while(temp!=null){
                    System.out.println(temp);
                    temp=getStringResponse(inputStream);
                }
                inputStream.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    /**
     * path不应该包含完整文件名，而应该时一个目录
     */
    class UploadHandler extends BaseSocketTransmission implements Runnable{
        Socket socket;
        String filePath;
        UploadHandler(String serverAddress,int port,String filePath)throws IOException{
            socket = new Socket(serverAddress, port);
            try {
                if (filePath.charAt(filePath.length() - 1) == CATALOGUE_NAME_END) {
                    throw new IOException();
                } else {
                    this.filePath = filePath;
                }
            } catch (IOException e) {
                try {
                    socket.close();
                } catch (IOException ex) {
                    // 处理关闭 socket 时可能抛出的异常
                    ex.printStackTrace();
                }
                throw e;
            }
        }

        @Override
        public void run(){
            try {
                //file是抽象的，需要inputstream进行真正的操作
                int index=filePath.lastIndexOf(CATALOGUE_NAME_END);
                File file=new File(filePath);
                PrivateProtocolFile privateProtocolFile=new PrivateProtocolFile(filePath.substring(index+1),file);
                File sendFile=new File(filePath+".serialize");
                if(!sendFile.exists()){
                    file.createNewFile();
                }
                serializeFileObject(privateProtocolFile,(filePath+".serialize"));

                OutputStream outputStream=socket.getOutputStream();
                sendFile(outputStream,sendFile);
                if(!sendFile.delete()){
                    throw new IOException("delete serialize file failed");
                }
                outputStream.close();
                socket.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }



    boolean circle(InputStream inputStream,OutputStream outputStream) throws IOException,InterruptedException{
        //解析命令并执行
        Scanner scanner=new Scanner(System.in);
        String inputCommand = scanner.nextLine();
        String[] commandArgs = inputCommand.split(" ");
        return parseCommand(commandArgs,inputStream,outputStream);
    }

    void execute()throws IOException,InterruptedException{
        //连接至服务器的监听端口
        Socket connectSocket = new Socket(SERVER_ADDRESS, SERVER_PORT);
        InputStream inputStream = connectSocket.getInputStream();

        //更换为新的常驻控制端口
        String controlPort=getStringResponse(inputStream);
        inputStream.close();
        connectSocket.close();
        Socket controlSocket = new Socket(SERVER_ADDRESS,Integer.parseInt(controlPort));

        while(circle(controlSocket.getInputStream(),controlSocket.getOutputStream())){

        }
    }

    void serializeCommandObject(){
        try (FileOutputStream fileOut = new FileOutputStream(commandPath);
             ObjectOutputStream out = new ObjectOutputStream(fileOut)) {
            out.writeObject(command);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    void deserializeCommandObject(){
        try (FileInputStream fileIn = new FileInputStream(commandPath);
             ObjectInputStream in = new ObjectInputStream(fileIn)) {
            command = (SocketCommand) in.readObject();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    void serializeFileObject(PrivateProtocolFile privateProtocolFile,String filePath){
        try (FileOutputStream fileOut = new FileOutputStream(filePath);
             ObjectOutputStream out = new ObjectOutputStream(fileOut)) {
            out.writeObject(privateProtocolFile);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 对完整路径名的文件进行逆序列化操作
     * @param filePath like C:\path\fileName
     * @return PrivateProtocolFile if normal, or back null with exception
     */
    PrivateProtocolFile deserializeFileObject(String filePath){
        try (FileInputStream fileIn = new FileInputStream(filePath);
             ObjectInputStream in = new ObjectInputStream(fileIn)) {
            PrivateProtocolFile file = (PrivateProtocolFile) in.readObject();
            return file;
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        return null;
    }

    public static void main(String[] args) throws IOException,InterruptedException{
        Client client=new Client();
        client.execute();
    }
}
