import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.LinkedList;
import java.util.Scanner;

public class Library {
    private final LinkedList<Book> BookList = new LinkedList<Book>();

    public void print() {
        System.out.println("序号\t\t状态\t\t名称\t\t借出日期");
        for (int i = 0; i < BookList.size(); i++) {
            System.out.print((i+1) + "\t\t");
            if (BookList.get(i).isAvailable()) {
                System.out.print("可借\t\t");
            } else {
                System.out.print("借出\t\t");
            }
            System.out.print(BookList.get(i).getName() + "\t\t");
            if (!BookList.get(i).isAvailable()) {
                System.out.println(BookList.get(i).getDate());
            } else {
                System.out.println();
            }
        }
        System.out.println("************************");
    }
    public boolean AddBook(String n) {
        if (BookList.size() == 50) return false;
        Book newbook = new Book(n);
        BookList.add(newbook);
        return true;
    }

    public int DelBook(String n) {
        for (Book i : BookList) {
            if (i.getName().equals(n)) {
                if (i.isAvailable()) {
                    BookList.remove(i);
                    return 1;//succeeded
                } else return -1;//occupied
            }
        }
        return 0;//not found
    }

    public int FindBook(String n) {
        for (Book i : BookList) {
            if (i.getName().equals(n)) {
                if (i.isAvailable()) {
                    return 1;//succeeded
                } else return -1;//occupied
            }
        }
        return 0;//not found
    }

    public void LendBook(String n, int y, int m, int d) {
        for (Book i : BookList) {
            if (i.getName().equals(n)) {
                i.setDate(y, m, d);
                i.setOcc();
                return;
            }
        }
    }

    public int DateCal(String s, String e) throws ParseException {
        SimpleDateFormat simpleFormat = new SimpleDateFormat("yyyy-MM-dd");
        Date startDate = simpleFormat.parse(s);
        Date endDate = simpleFormat.parse(e);
        long startTime = startDate.getTime();
        long endTime = endDate.getTime();
        return (int) ((endTime - startTime) / (1000 * 60 * 60 * 24));
    }

    public void ReturnBook(String n, String e) throws ParseException {
        for (Book i : BookList) {
            if (i.getName().equals(n)) {
                if (i.isAvailable()) {
                    System.out.println("该图书没有被借出！无法进行归还操作。");
                    return;
                }
                System.out.println("归还《" + n + "》成功！");
                System.out.println("借出日期：" + i.getDate());
                System.out.println("归还日期：" + e);
                System.out.println("应付租金（元）：" + DateCal(i.getDate(), e));
                return;
            }
        }
        System.out.println("没有找到匹配信息！");
    }

    public void menu() throws ParseException {
        System.out.println("欢迎使用图书借阅系统");
        System.out.println("--------------------------------");
        System.out.println("0. 借出排行榜");
        System.out.println("1. 新增图书");
        System.out.println("2. 查看图书");
        System.out.println("3. 删除图书");
        System.out.println("4. 借出图书");
        System.out.println("5. 归还图书");
        System.out.println("6. 退出");
        System.out.println("--------------------------------");
        System.out.print("请选择：");
        Scanner scan1 = new Scanner(System.in);
        int choose = scan1.nextInt();
        System.out.print("--->");
        switch (choose) {
            case 1:
                System.out.println("新增图书");
                System.out.print("请输入图书名称：");
                Scanner scan2 = new Scanner(System.in);
                String newBook = scan2.next();
                if (AddBook(newBook)) {
                    System.out.println("新增《" + newBook + "》成功！");
                } else {
                    System.out.println("增加失败！书架已满。");
                }
                System.out.println("************************");
                System.out.print("输入0返回：");
                Scanner scan0 = new Scanner(System.in);
                int rtnRslt = scan0.nextInt();
                if (rtnRslt == 0) menu();
                else {
                    System.out.println("输入有误，系统退出。");
                }
                break;
            case 2:
                System.out.println("查看图书");
                print();
                System.out.print("输入0返回：");
                scan0 = new Scanner(System.in);
                rtnRslt = scan0.nextInt();
                if (rtnRslt == 0) menu();
                else {
                    System.out.println("输入有误，系统退出。");
                }
                break;
            case 3:
                System.out.println("删除图书");
                System.out.print("请输入图书名称：");
                Scanner scan3 = new Scanner(System.in);
                String delBook = scan3.next();
                switch (DelBook(delBook)) {
                    case 1 -> System.out.println("删除《" + delBook + "》成功！");
                    case 0 -> System.out.println("没有找到匹配信息！");
                    case -1 -> System.out.println("图书为借出状态，不允许删除！");
                    default -> {
                    }
                }
                System.out.print("输入0返回：");
                scan0 = new Scanner(System.in);
                rtnRslt = scan0.nextInt();
                if (rtnRslt == 0) menu();
                else System.out.println("输入有误，系统退出。");
                break;
            case 4:
                System.out.println("借出图书");
                System.out.print("请输入图书名称：");
                Scanner scan4 = new Scanner(System.in);
                String lendBook = scan4.next();
                boolean find = true;
                switch (FindBook(lendBook)) {
                    case 1 -> System.out.print("请输入借出日期（年-月-日）：");
                    case 0 -> {
                        System.out.println("没有找到匹配信息！");
                        find = false;
                    }
                    case -1 -> {
                        System.out.println("《" + lendBook + "》已被借出。");
                        find = false;
                    }
                    default -> {
                    }
                }
                if (find) {
                    Scanner scan5 = new Scanner(System.in);
                    String dateStr = scan5.next();
                    Date date = new SimpleDateFormat("yyyy-MM-dd").parse(dateStr);
                    Calendar ca = Calendar.getInstance();
                    ca.setTime(date);
                    int d = ca.get(Calendar.DATE);
                    int m = ca.get(Calendar.MONTH)+1;
                    int y = ca.get(Calendar.YEAR);
                    LendBook(lendBook, y, m, d);
                    System.out.println("借出《" + lendBook + "》成功！");
                }
                System.out.println("************************");
                System.out.print("输入0返回：");
                scan0 = new Scanner(System.in);
                rtnRslt = scan0.nextInt();
                if (rtnRslt == 0) menu();
                else System.out.println("输入有误，系统退出。");
                break;
            case 5:
                System.out.println("归还图书");
                System.out.print("请输入图书名称：");
                Scanner scan5 = new Scanner(System.in);
                String rtnBook = scan5.next();
                System.out.print("请输入归还日期：");
                Scanner scan6 = new Scanner(System.in);
                String e = scan6.next();
                ReturnBook(rtnBook, e);
                System.out.println("************************");
                System.out.print("输入0返回：");
                scan0 = new Scanner(System.in);
                rtnRslt = scan0.nextInt();
                if (rtnRslt == 0) menu();
                else System.out.println("输入有误，系统退出。");
                break;
            case 6:
                System.out.println("拜拜！");
                return;
            default:
        }
    }

}
