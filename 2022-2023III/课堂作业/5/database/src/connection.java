import java.sql.*;

public class connection {
    static String driver = "org.postgresql.Driver";
    //数据库连接描述符。
    static String sourceURL = "jdbc:postgresql://120.46.206.97:26000/mydb";
    static Connection conn = null;
    public static Connection getConnect()
    {      

        try
        {
            //加载驱动。
            Class.forName(driver);
        }
        catch( Exception e )
        {
            e.printStackTrace();
            return null;
        }

        try
        {
            //创建连接。
            conn = DriverManager.getConnection(sourceURL, "oguser", "Jbx200259");
            System.out.println("Connection succeed!");
        }
        catch(Exception e)
        {
            e.printStackTrace();
            return null;
        }

        return conn;
    };
    public void sql(){
        Statement stmt = null;
        try{
            getConnect();

            // 执行查询
            System.out.println(" 实例化Statement对象...");
            stmt = conn.createStatement();
            String sql;
            sql = "SELECT num, user_name FROM JAVA";
            ResultSet rs = stmt.executeQuery(sql);

            // 展开结果集数据库
            while(rs.next()){
                // 通过字段检索
                int id  = rs.getInt("num");
                String name = rs.getString("user_name");

                // 输出数据
                System.out.print("ID: " + id);
                System.out.print(", 名称: " + name);
                System.out.print("\n");
            }
            // 完成后关闭
            ((ResultSet) rs).close();
            ((Statement) stmt).close();
            conn.close();
        }catch(SQLException se){
            // 处理 JDBC 错误
            se.printStackTrace();
        }catch(Exception e){
            // 处理 Class.forName 错误
            e.printStackTrace();
        }finally{
            // 关闭资源
            try{
                if(stmt!=null) stmt.close();
            }catch(SQLException se2){
            }// 什么都不做
            try{
                if(conn!=null) conn.close();
            }catch(SQLException se){
                se.printStackTrace();
            }
        }
        System.out.println("Goodbye!");
    }

}
