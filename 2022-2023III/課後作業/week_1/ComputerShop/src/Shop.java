import java.util.LinkedList;
import java.util.Scanner;

public class Shop {
    public int b = 0;
    LinkedList<Computer> shop = new LinkedList<Computer>();

    public Shop() {
        shop.add(new PC("DELL", 8, "1T\t", 14, "I7", "立式", 6000));
        shop.add(new Desktop("联想", 4, "500G", 10, "I5", 9, 4500));
    }

    private void print() {
        System.out.println("序号\t\t品牌 \t类型\t\t内存\t\t硬盘\t\t显示器\tCPU\t\t电池\t\t机箱\t\t价格（元）");
        for (int i = 0; i < shop.size(); i++) {
            System.out.print(i + 1 + "\t\t");
            System.out.print(shop.get(i).getBrand() + " \t" + shop.get(i).getType() + " \t" + shop.get(i).getMemory() + "G\t\t" + shop.get(i).getDisk() + " \t" + shop.get(i).getDisplay() + "寸\t" + shop.get(i).getCpu());
            if (shop.get(i).getType().equals("台式机")) {
                System.out.print("\t\t\t\t" + shop.get(i).getChassis() + "\t\t");
            } else {
                System.out.print("\t\t" + shop.get(i).getBattery() + "芯\t\t\t\t");
            }
            System.out.println(shop.get(i).getPrice());
        }
    }

    private void buy(int b) {
        if (b == 0) {
            System.out.println("您还没有选择电脑!");
            return;
        }
        System.out.println("请选择支付方式：\t1、完整支付\t2、分期支付");
        Scanner scan2 = new Scanner(System.in);
        int choose2 = scan2.nextInt();
        switch (choose2) {
            case 1:
                System.out.println("你选择了完整支付，价格为：" + shop.get(b - 1).getPrice() + "元，可以选择赠品：（1、鼠标\t2、U盘）");
                Scanner scan3 = new Scanner(System.in);
                int choose3 = scan3.nextInt();
                switch (choose3) {
                    case 1 ->
                            System.out.println("恭喜你购买了" + shop.get(b - 1).getBrand() + shop.get(b - 1).getType() + "，价格为" + shop.get(b - 1).getPrice() + "元,赠品为鼠标。");
                    case 2 ->
                            System.out.println("恭喜你购买了" + shop.get(b - 1).getBrand() + shop.get(b - 1).getType() + "，价格为" + shop.get(b - 1).getPrice() + "元,赠品为U盘。");
                    default -> {
                        System.out.println("输入有误，程序退出。");
                        return;
                    }
                }
                break;
            case 2:
                System.out.println("你选择了分期支付，价格为：" + shop.get(b - 1).getPrice() + "元，可以选择周期：（1、12期\t2、24期）");
                Scanner scan4 = new Scanner(System.in);
                int choose4 = scan4.nextInt();
                switch (choose4) {
                    case 1 ->
                            System.out.println("恭喜你购买了" + shop.get(b - 1).getBrand() + shop.get(b - 1).getType() + "，价格为" + shop.get(b - 1).getPrice() + "元,分12期付款。");
                    case 2 ->
                            System.out.println("恭喜你购买了" + shop.get(b - 1).getBrand() + shop.get(b - 1).getType() + "，价格为" + shop.get(b - 1).getPrice() + "元,分24期付款。");
                    default -> {
                        System.out.println("输入有误，程序退出。");
                        return;
                    }
                }
                break;
            default:
                System.out.println("输入有误，程序退出。");
                return;
        }
    }

    public void menu() {
        System.out.println("1、查看电脑信息\t2、购买电脑");
        Scanner scan1 = new Scanner(System.in);
        int choose1 = scan1.nextInt();
        switch (choose1) {
            case 1 -> {
                print();
                boolean ctn = false;
                while (!ctn) {
                    System.out.print("请选择要购买的电脑：");
                    Scanner choose3 = new Scanner(System.in);
                    b = choose3.nextInt();
                    if (b <= shop.size() && b > 0) {
                        ctn = true;
                        break;
                    }
                    System.out.println("选择序号有误！");
                }
                buy(b);
            }
            case 2 -> buy(b);
            default -> {
                System.out.println("输入有误，程序退出。");
                return;
            }
        }
        System.out.println("******欢迎下次光临******");
    }
}

