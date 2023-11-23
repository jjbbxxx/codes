// 按两次 Shift 打开“随处搜索”对话框并输入 `show whitespaces`，
// 然后按 Enter 键。现在，您可以在代码中看到空格字符。
public class Main {
    public static void main(String[] args) {
                System.out.println("前10个数是：");
                int a[];
                a= new int[10];
                a[0]=1;
                a[1]=1;
                System.out.println(a[0]);
                System.out.println(a[1]);
                for(int i=2;i<a.length;i++){
                    a[i]=a[i-1]+a[i-2];
                    System.out.println(a[i]);
                }
            }
    }