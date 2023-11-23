import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;

public class Main {
    public static void main(String[] args) throws IOException {
        File outfile = new File("JayChou.txt");

        // 检查scores.txt是否存在，如果存在退出程序
        // 如果想实现重写覆盖，把这段注释掉就可以了
        if (outfile.exists()) {
            System.out.println("File already exists.");
            System.exit(1);
        }

        // 如果不存在则写文件
        // 为了避免一些乱码问题，我们制定编码方式为 UTF-8
        PrintWriter out = new PrintWriter(outfile, StandardCharsets.UTF_8);
        out.print("Jay chou ");
        out.println("is a pop music star.");
        out.println("稻香");
        out.println("夜曲");
        out.println("青花瓷");

        // 释放资源
        out.close();



    }
}