public class PC extends Computer{
    String chassis;

    @Override
    public int getBattery() {
        return 0;
    }

    public String getChassis() {
        return chassis;
    }

    public void setChassis(String chassis) {
        this.chassis = chassis;
    }
    public PC(String b, int m, String d, int dp, String c, String cs, int p) {
        setBrand(b);
        setType("台式机");
        setMemory(m);
        setDisk(d);
        setDisplay(dp);
        setCpu(c);
        setChassis(cs);
        setPrice(p);
    }
}
