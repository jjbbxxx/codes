import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

/**
 * 命令传输对象，请使用
 */
public class SocketCommand implements Serializable {
    private String command;
    private HashMap<String,String>option=new HashMap<>();
    void addOptionAndValue(String option,String value){
        this.option.put(option,value);
    }
    void setCommand(String command){
        this.command=command;
    }
    public String getCommand() {
        return command;
    }

    Set<Map.Entry<String,String>> getOptionAndValue(){
        return option.entrySet();
    }

}
