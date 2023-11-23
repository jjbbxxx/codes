//导入sql包
import java.sql.*;
public class BaseDao{
    //用的8.0.11的驱动包，所以和以往的驱动包不同，增加了一个cj
    private static String driver = "com.mysql.cj.jdbc.Driver";
    //数据库地址，新版的驱动包在url地址处需指明是否加上SSL连接和加上时区，此处为北京时区
    private static String  url = "jdbc:mysql://127.0.0.1:3306/test?useSSL=FALSE&serverTimezone=GMT%2B8";
    //数据库用户名属性
    private static String name = "root";
    //数据库密码属性
    private static String password = "123456";
    //数据库连接，定义为全局变量，方便调用
    private Connection con;
    //导入驱动，静态代码块的作用为只运行一次,异常无法向上抛出，只能及时处理
    static{
        try{
            Class.forName(driver);
        }catch (ClassNotFoundException e) {
            //打印异常相关信息
            e.printStackTrace();
        }
    }
    //无参构造方法，连接数据库
    public BaseDao () {
        try {
            con=DriverManager.getConnection(url,name,password);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    //数据查找，返回查找的内容，向上抛异常
    public ResultSet executeQuery (String sql,Object...object) throws SQLException{
        PreparedStatement ps=con.prepareStatement(sql);
        for(int i=0;i<object.length;i++){
      //传入参数的下标是从1开始
            ps.setObject(i+1,object[i]);
        }
        //返回结果集
        return ps.executeQuery();
    }
    //数据的增删改，返回数据执行行数
    public int executeUpdate(String sql,Object...object) throws SQLException {
        PreparedStatement ps=con.prepareStatement(sql);
        for(int i=0;i<object.length;i++){
            ps.setObject(i+1,object[i]);
        }
        //返回int类型执行行数
        return ps.executeUpdate();
    }
    //关闭数据库连接
    public void close() throws SQLException{
        con.close();
    }
}
