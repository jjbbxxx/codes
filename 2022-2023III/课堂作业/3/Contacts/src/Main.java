/*
 * @author: jbx
 */

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        Contacts contacts = new Contacts();
        contacts.AddPeople("jbx","13000000000","aaa","123@abc");
        contacts.AddPeople("lcx"," \t\t","bbb","456@abc");
        contacts.menu();
    }
}