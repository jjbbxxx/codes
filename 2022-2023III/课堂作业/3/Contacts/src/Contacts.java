import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.LinkedList;
import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

/*
 * @author: jbx
 */

public class Contacts {
    private final LinkedList<People> peopleList = new LinkedList<People>();

    public File outfile=new File("Contacts.txt");
    public void printToFile() throws IOException {
        PrintWriter out = new PrintWriter(outfile, StandardCharsets.UTF_8);
        out.println("序号\t姓名\t\t电话\t\t\t\t地址\t\tEmail");
        System.out.println("正在打印");
        for (int i = 0; i < peopleList.size(); i++) {
            out.print((i + 1) + "\t");
            out.print(peopleList.get(i).getName() + "\t\t");
            out.print(peopleList.get(i).getPhone() + "\t\t");
            out.print(peopleList.get(i).getAddress() + "\t\t");
            out.print(peopleList.get(i).getEmail() + "\t\t");
            out.println();
        }
        System.out.println("打印完成,文件在"+outfile.getAbsolutePath());
        out.close();
    }
    //print contacts to file
    public void print() throws IOException {
        System.out.println("序号\t姓名\t\t电话\t\t\t\t地址\t\tEmail");
        for (int i = 0; i < peopleList.size(); i++) {
            System.out.print((i + 1) + "\t");
            System.out.print(peopleList.get(i).getName() + "\t\t");
            System.out.print(peopleList.get(i).getPhone() + "\t\t");
            System.out.print(peopleList.get(i).getAddress() + "\t\t");
            System.out.print(peopleList.get(i).getEmail() + "\t\t");
            System.out.println();
        }
    }
    //print contacts

    public boolean AddPeople(String n, String p, String a, String e) {
        if (FindPeople(n)) return false;//已存在名为n的联系人
        People newPeople = new People(n, p, a, e);
        peopleList.add(newPeople);
        return true;
    }
    //add people

    public boolean DelPeople(String n) {
        for (People i : peopleList) {
            if (i.getName().equals(n)) {
                peopleList.remove(i);
                return true;//succeeded
            }
        }
        return false;//not found
    }
    //delete people

    public boolean FindPeople(String n) {
        for (People i : peopleList) {
            if (i.getName().equals(n)) {
                return true;//succeeded
            }
        }
        return false;//not found
    }
    //find people

    public boolean EditPeople(String n) {
        if (!FindPeople(n)) return false;
        else {
            for (People i : peopleList) {
                if (i.getName().equals(n)) {
                    System.out.println("请选择要编辑的数据：");
                    System.out.println("---------");
                    System.out.println("1. 姓名");
                    System.out.println("2. 电话");
                    System.out.println("3. 地址");
                    System.out.println("4. Email");
                    System.out.println("---------");
                    Scanner scan = new Scanner(System.in);
                    int editNum = scan.nextInt();
                    switch (editNum) {
                        case 1 -> {
                            System.out.println("请输入新姓名：");
                            scan = new Scanner(System.in);
                            String newName = scan.next();
                            i.setName(newName);
                            System.out.println("修改新姓名" + newName + "成功！");
                        }
                        case 3 -> {
                            System.out.println("请输入新地址：");
                            scan = new Scanner(System.in);
                            String newAdd = scan.next();
                            i.setAddress(newAdd);
                            System.out.println("修改新地址" + newAdd + "成功！");
                        }
                        case 2 -> {
                            System.out.println("请输入新电话：");
                            scan = new Scanner(System.in);
                            String newPhone = scan.next();
                            i.setPhone(newPhone);
                            System.out.println("修改新电话" + newPhone + "成功！");
                        }
                        case 4 -> {
                            System.out.println("请输入新Email：");
                            scan = new Scanner(System.in);
                            String newEmail = scan.next();
                            i.setEmail(newEmail);
                            System.out.println("修改新Email" + newEmail + "成功！");
                        }
                        default -> {
                        }
                    }
                }
            }
        }
                return true;//succeeded
    }

    public void menu() throws IOException {
        System.out.println("-----------");
        System.out.println("通讯录");
        System.out.println("1. 查看联系人");
        System.out.println("2. 添加联系人");
        System.out.println("3. 删除联系人");
        System.out.println("4. 修改联系人");
        System.out.println("5. 退出通讯录");
        System.out.println("6. 导出通讯录");
        System.out.println("------------");
        System.out.print("请选择：");
        Scanner scan1 = new Scanner(System.in);
        int choose = scan1.nextInt();
        System.out.print("--->");
        switch (choose) {
            case 2 -> {
                System.out.println("添加联系人");
                System.out.print("请输入联系人名称：");
                Scanner scan2 = new Scanner(System.in);
                String newPeopleName = scan2.next();
                System.out.print("请输入联系人电话,输入0留空：");
                scan2 = new Scanner(System.in);
                String newPeoplePhone = scan2.next();
                if (newPeoplePhone.equals("0")) newPeoplePhone = " \t\t";
                System.out.print("请输入联系人地址,输入0留空：");
                scan2 = new Scanner(System.in);
                String newPeopleAdd = scan2.next();
                if (newPeopleAdd.equals("0")) newPeopleAdd = "";
                System.out.print("请输入联系人Email,输入0留空：");
                scan2 = new Scanner(System.in);
                String newPeopleEmail = scan2.next();
                if (newPeopleEmail.equals("0")) newPeopleEmail = "";
                if (AddPeople(newPeopleName, newPeoplePhone, newPeopleAdd, newPeopleEmail)) {
                    System.out.println("新增联系人" + newPeopleName + "成功！");
                } else {
                    System.out.println("新增联系人失败，联系人已存在。");
                }
                menu();
            }
            case 1 -> {
                System.out.println("查看联系人");
                print();
                menu();
            }
            case 3 -> {
                System.out.println("删除联系人");
                System.out.print("请输入联系人名称：");
                Scanner scan3 = new Scanner(System.in);
                String delPeople = scan3.next();
                if (DelPeople(delPeople)) {
                    System.out.println("删除联系人" + delPeople + "成功！");
                } else {
                    System.out.println("联系人不存在。");
                }
                menu();
            }
            case 4 -> {
                System.out.println("编辑联系人");
                System.out.print("请输入联系人名称：");
                Scanner scan4 = new Scanner(System.in);
                String editPeople = scan4.next();
                if (EditPeople(editPeople)) {
                    System.out.println("编辑联系人" + editPeople + "成功！");
                } else {
                    System.out.println("联系人不存在。");
                }
                menu();
            }
            case 5 -> {
                System.out.println("拜拜！");
                return;
            }
            case 6->{
                System.out.println("导出通讯录");
                printToFile();
                menu();
            }
            default -> {
            }
        }
    }

}
