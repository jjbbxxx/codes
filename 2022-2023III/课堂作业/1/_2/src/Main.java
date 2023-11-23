import java.util.Scanner;

// 按两次 Shift 打开“随处搜索”对话框并输入 `show whitespaces`，
// 然后按 Enter 键。现在，您可以在代码中看到空格字符。
public class Main {
    public static void main(String[] args) {
        int number = (int)(Math.random()*100);
        boolean x= false;
        int count=0;
        System.out.println("我心里有一个0-99的数，你猜是什么？");
        while(x==false){
            Scanner in=new Scanner(System.in);
            int guess=in.nextInt();
            if(guess>number){
                System.out.println("大了");
                count++;
            }
            else if (guess<number) {
                System.out.println("小了");
                count++;
            }
            else  {System.out.println("猜对了！");
                count++;
                x=true;
            }
        }
        if(count==1)
            System.out.println("你太聪明了！");
        else if (count<6) {
            System.out.println("不错，再接再厉！");
        }
        else {
            System.out.println("要努力啊！");
        }
    }
}