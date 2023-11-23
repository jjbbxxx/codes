import java.io.*;

/**
 * 创建私有文件协议以同时传输文件名和文件内容。
 */
public class PrivateProtocolFile implements Serializable {
    private String filename;
    private byte[] filedata;

    PrivateProtocolFile(){};

    /**
     * 保存文件和文件名，以一次传输两者
     * @param filename
     * @param file
     */
    PrivateProtocolFile(String filename, File file){
        this.filename=filename;
        try {
            // 创建一个与文件相关联的 FileInputStream
            FileInputStream fis = new FileInputStream(file);
            // 获取文件长度
            long fileSize = file.length();
            // 赋值字节数组来保存文件内容
            filedata = new byte[(int) fileSize];
            // 读取文件内容到字节数组
            fis.read(filedata);
            // 关闭 FileInputStream
            fis.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 将对象转化为文件，附带文件名
     * @param filename 完整的目录路径(以“\”结尾，如C:\\download\\)，
     *                 函数将对象转化为该目录下的文件，文件名基于对象.
     */
    void toFile(String filename)throws IOException{
        File file=new File(filename+this.filename);
        FileOutputStream fileOutputStream=new FileOutputStream(file);
        fileOutputStream.write(filedata);
    }

}
