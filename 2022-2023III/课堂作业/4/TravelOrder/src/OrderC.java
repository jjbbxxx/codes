public class OrderC extends OrderA{


    public OrderC(String n,int a,String b) {
        setName(n);
        setAge(a);
        setBed(b);
        if(b.equals("是")){
            setCharge(30);
        }
        else {
            setCharge(0);
        }
    }
public void setBed(String bed){
        this.bed=bed;
}


}
