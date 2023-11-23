public class emp extends inc{
    private String name;
    private int salary=0;
    private int subsidy=0;
    private double tax=0;
    private int all;
    private int taxx;

    public emp(){

    }
//    public emp(String n,int sal, int sub){
//        setName(n);
//        setSalary(sal);
//        setSubsidy(sub);
//    }
    public void setName(String n){
        name= n;
    }
    public void setSalary(int sal){
        salary=sal;
    }
    public void setSubsidy(int sub){
        subsidy=sub;
    }
    public int getSalary(){
        return salary;
    }
    public int getSubsidy(){
        return subsidy;
    }
    public void taxcal(){
        all=getSalary()+getSubsidy();
        if(all<2000)tax=0;
        else {
            taxx=all-2000;
            if(taxx>20000)tax=taxx*0.3;
            else if (taxx>5000)tax=taxx*0.2;
            else if(taxx>2000)tax=tax*0.15;
            else if(taxx>500)tax=taxx*0.1;
            else tax=taxx*0.05;
        }
    }
    public void tax(){
        this.income();
        setName(incname);
        setSalary(incsalary);
        setSubsidy(incsubsidy);
        this.taxcal();
        System.out.println("员工"+name+"的税前收入为"+all+"元，税后收入为"+(all-tax)+"元，您缴纳的个人所得税为"+tax+"元。");
    }
}
