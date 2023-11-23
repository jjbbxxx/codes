import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;

public class Test {
    LinkedList <OrderA> OrderList= new LinkedList<>();
    Tool tool=new Tool();
    public void menu() throws FileNotFoundException {
        System.out.println("********欢迎光临阳光旅游网*********");
        System.out.print("1. 添加出行订单\t");
        System.out.print("2. 查看我的出行订单\t");
        System.out.print("3. 修改订单信息\t");
        System.out.print("4. 删除出行人\t");
        System.out.print("5. 查看行程\t");
        System.out.println("6. 退出系统");
        System.out.print("请选择（1-6）：");
        Scanner scan1 = new Scanner(System.in);
        int choose = scan1.nextInt();
        switch (choose) {
            case 1 -> {
                tool.AddOrder(OrderList);
                menu();
            }
            case 2 -> {
                tool.PrintOrder(OrderList);
                menu();
            }
            case 3 -> {
                tool.EditOrder(OrderList);
                menu();
            }
            case 4 -> {
                tool.DelOrder(OrderList);
                menu();
            }
            case 5 -> {
                tool.show();
                menu();
            }
            case 6 -> {
                System.out.println("拜拜！");
            }
            default -> {
                System.out.println("输入有误！");
                menu();
            }
        }

    }
}
