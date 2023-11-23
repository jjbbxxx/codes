public class OrderA {

    String name;
    int age;
    int charge;
    int Date;
    long Phone;
    String bed=null;


    public OrderA() {
    }

    public OrderA(String name, int age) {
        this.name = name;
        this.age = age;
        this.setCharge();
    }




    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getCharge() {
        return charge;
    }

    public void setCharge(int charge) {
        this.charge = charge;
    }
    public void setCharge(){
        this.charge=2000;
    }

    public int getDate() {
        return Date;
    }

    public void setDate(int date) {
        this.Date = date;
    }

    public long getPhone() {
        return Phone;
    }

    public void setPhone(long phone) {
        this.Phone = phone;
    }

    public String getBed() {
        return bed;
    }
}
