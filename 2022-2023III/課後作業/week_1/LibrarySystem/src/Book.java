public class Book {
    private String name;
    private boolean available = true;
    private int year, month, date;

    public Book() {

    }


    public Book(String n) {
        name = n;
    }

    public void setDate(int y, int m, int d) {

            year = y;
            month = m;
            date = d;
    }


    public void setAva() {
            available = true;
    }

    public void setOcc() {
            available = false;
    }


    public String getName() {
        return name;
    }

    public boolean isAvailable() {
        return available;
    }

    public String getDate() {
        return year +"-"+ month +"-"+ date;
    }
}
