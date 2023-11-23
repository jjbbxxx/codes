import java.util.Scanner;

public class inc{
    public String incname;
    public int incsalary;
    public int incsubsidy;
    public void income(){
        System.out.print("请输入员工的姓名：");
        Scanner scan1= new Scanner(System.in);
        incname=scan1.next();
        System.out.print("请输入员工工资：");
        Scanner scan2= new Scanner(System.in);
        incsalary=scan2.nextInt();
        System.out.print("请输入员工加班补贴：");
        Scanner scan3= new Scanner(System.in);
        incsubsidy=scan3.nextInt();

    }
}
