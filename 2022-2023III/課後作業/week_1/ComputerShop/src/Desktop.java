public class Desktop extends Computer{
    int battery;

    public int getBattery() {
        return battery;
    }

    @Override
    public String getChassis() {
        return null;
    }

    public void setBattery(int battery) {
        this.battery = battery;
    }

    public Desktop(String b, int m, String d, int dp, String c, int btr, int p) {
        setBrand(b);
        setType("笔记本");
        setMemory(m);
        setDisk(d);
        setDisplay(dp);
        setCpu(c);
        setBattery(btr);
        setPrice(p);
    }
}
