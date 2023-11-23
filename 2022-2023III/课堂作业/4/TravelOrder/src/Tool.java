import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;

public class Tool {
    public void AddOrder(LinkedList<OrderA> OL) {
        System.out.print("请输入出行日期（如：20170501）");
        Scanner scan1 = new Scanner(System.in);
        int date = scan1.nextInt();
        boolean check1 = true;
        long phone = 0;
        while (check1) {
            System.out.print("请输入联系人手机号码:");
            Scanner scan2 = new Scanner(System.in);
            phone = scan2.nextLong();
            if (phone >= 10000000000L && phone <= 99999999999L) {
                check1 = false;
            } else {
                throw new IllegalArgumentException("手机号码必须为11位");
            }
        }
        OL.add(0, new OrderInfo(date, phone));
        boolean check2 = true;
        System.out.println("******添加出行人信息******");
        while (check2) {
            System.out.print("1.成人 2.儿童（1.2米以下） 3.老人（65岁以上） 请选择类别：");
            Scanner scan3 = new Scanner(System.in);
            int choose = scan3.nextInt();
            switch (choose) {
                case 1:
                    System.out.print("请输入姓名：");
                    Scanner scan4 = new Scanner(System.in);
                    String newName = scan4.next();
                    System.out.print("请输入年龄：");
                    scan4 = new Scanner(System.in);
                    int newAge = scan4.nextInt();
                    OrderA newA = new OrderA(newName, newAge);
                    OL.add(newA);
                    System.out.println("姓名：" + newA.getName() + "，年龄：" + newA.getAge() + "\t本次出行金额:" + newA.getCharge() + "元。");
                    System.out.print("是否继续添加（Y/N）：");
                    Scanner scan5 = new Scanner(System.in);
                    String yn = scan5.next();
                    if (yn.equals("n") || yn.equals("N")) check2 = false;
                    break;
                case 2:
                    System.out.print("请输入姓名：");
                    scan4 = new Scanner(System.in);
                    newName = scan4.next();
                    System.out.print("请输入年龄：");
                    scan4 = new Scanner(System.in);
                    newAge = scan4.nextInt();
                    System.out.print("是否占床：1.占床 2.不占床\t");
                    scan4 = new Scanner(System.in);
                    int bedCheck = scan4.nextInt();
                    String newBed;
                    newBed = (bedCheck == 1 ? "是" : "否");
                    OrderC newC = new OrderC(newName, newAge, newBed);
                    OL.add(newC);
                    System.out.print("姓名：" + newC.getName() + "，年龄：" + newC.getAge());
                    if (newBed.equals("是")) System.out.print("，占床\t");
                    else System.out.print("，不占床\t");
                    System.out.println("1.2m以下儿童免费（占床费除外），本次出行金额：" + newC.getCharge() + "元。");
                    System.out.print("是否继续添加（Y/N）：");
                    scan5 = new Scanner(System.in);
                    yn = scan5.next();
                    if (yn.equals("n") || yn.equals("N")) check2 = false;
                    break;
                case 3:
                    System.out.print("请输入姓名：");
                    scan4 = new Scanner(System.in);
                    newName = scan4.next();
                    boolean check3 = true;
                    newAge = 0;
                    while (check3) {
                        System.out.print("请输入年龄：");
                        scan4 = new Scanner(System.in);
                        newAge = scan4.nextInt();
                        if (newAge < 65) System.out.println("对不起，老人订单年龄需为65岁以上！");
                        else check3 = false;
                    }
                    OrderO newO = new OrderO(newName, newAge);
                    OL.add(newO);
                    System.out.println("姓名：" + newO.getName() + "，年龄：" + newO.getAge() + "\t65岁以上老人半价，本次出行金额:" + newO.getCharge() + "元。");
                    System.out.print("是否继续添加（Y/N）：");
                    scan5 = new Scanner(System.in);
                    yn = scan5.next();
                    if (yn.equals("n") || yn.equals("N")) check2 = false;
                    break;
                default:
                    System.out.println("输入有误！");
            }
        }
        int total = 0;
        for (int i = 1; i < OL.size(); i++) {
            total += OL.get(i).getCharge();
        }
        System.out.println("******订单信息*****");
        System.out.println("出行日期：" + OL.get(0).getDate());
        System.out.println("联系人手机号码：" + OL.get(0).getPhone());
        System.out.println("订单总金额：" + total + "元。");
    }

    public void PrintOrder(LinkedList<OrderA> OL) {
        System.out.println("出行日期：" + OL.get(0).getDate());
        System.out.println("联系人手机号码：" + OL.get(0).getPhone());
        System.out.println("详细信息：");
        System.out.println("姓名\t\t年龄\t占床\t金额");
        for (int i = 1; i < OL.size(); i++) {
            System.out.print(OL.get(i).getName() + " \t \t" + OL.get(i).getAge() + "\t");
            if (OL.get(i).getBed() == null) System.out.print("\t");
            else if (OL.get(i).getBed().equals("是")) System.out.print("是\t");
            else if (OL.get(i).getBed().equals("否")) System.out.print("否\t");
            System.out.println(OL.get(i).getCharge());
        }
    }

    public void EditOrder(LinkedList<OrderA> OL) {
        System.out.print("请输入新的出行日期:");
        Scanner scan1 = new Scanner(System.in);
        int date = scan1.nextInt();
        boolean check1 = true;
        long phone = 0;
        while (check1) {
            System.out.print("请输入新的联系人手机号码:");
            Scanner scan2 = new Scanner(System.in);
            phone = scan2.nextLong();
            if (phone >= 10000000000L && phone <= 99999999999L) {
                check1 = false;
            } else {
                throw new IllegalArgumentException("手机号码必须为11位");
            }
        }
        OL.get(0).setDate(date);
        OL.get(0).setPhone(phone);
        System.out.print("出行日期：" + OL.get(0).getDate());
        System.out.print("，联系人手机号码：" + OL.get(0).getPhone());
        System.out.println("，修改成功！");
    }

    public void DelOrder(LinkedList<OrderA> OL) {
        System.out.print("请输入要删除的出行人姓名：");
        Scanner scan1 = new Scanner(System.in);
        String delName = scan1.next();
        for (int i = 1; i < OL.size(); i++) {
            if (OL.get(i).getName().equals(delName)) {
                OL.remove(i);
                System.out.println("删除成功！");
                return;
            }
        }
        System.out.println("对不起，订单中不包含此游客信息！");
    }

    public void show() throws FileNotFoundException {
        File infile = new File("旅游行程.txt");
        Scanner in = new Scanner(infile, "UTF-8");
        while (in.hasNext()) {
            String s = in.nextLine();
            System.out.println(s);
        }
        in.close();
    }
}
