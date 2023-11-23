import entity.RecommenderEntity;
import interface_.RecommenderDao;
import com.mysql.jdbc.Driver;
import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class RecommenderMysqlImpleDao implements RecommenderDao {
    public static String diverName="com.mysql.cj.jdbc.Driver";
    public static String url = "jdbc:mysql://192.168.1.102:3306/shop?useUnicode=true&characterEncoding=UTF-8";
    public static String userName="root";
    public static String password="you235..hedan";
    public static Connection getConnection() throws ClassNotFoundException, SQLException {
        Class.forName(diverName);//加载
        //指定用户名和密码
        Connection conn = DriverManager.getConnection(url, userName,password);
        return conn;
    }
    @Override
    public RecommenderEntity getRecommender(String id) throws SQLException, ClassNotFoundException {
        String sql="select recommender_name from recommender where recommender_id="+id;
        System.out.println(sql);
        Connection conn = RecommenderMysqlImpleDao.getConnection();
        //创建Statement对象
        PreparedStatement ps=conn.prepareStatement(sql);
        ResultSet rs = ((PreparedStatement) ps).executeQuery(sql);
        List<Map<String, Object>> list = rsToList(rs);
        closeConnection(conn, ps, rs);//关闭
        return (RecommenderEntity) list;
    }
    @Override
    public int addRecommender(String id, String name) throws SQLException, ClassNotFoundException {
        String sql="insert into recommender values("+id+","+name+")";
        System.out.println(sql);
        Connection conn = RecommenderMysqlImpleDao.getConnection();//连接
        PreparedStatement ps=conn.prepareStatement(sql);
        int count = ps.executeUpdate(sql);//执行
        this.releaseConnection(conn, ps);//关闭
        return count;
    }
    @Override
    public void delRecommender(String id) throws SQLException, ClassNotFoundException {
        String sql="delete from recommender where recommender_id="+id;
        System.out.println(sql);
        Connection conn = RecommenderMysqlImpleDao.getConnection();//连接
        PreparedStatement ps=conn.prepareStatement(sql);
        int count = ps.executeUpdate(sql);//执行
        this.releaseConnection(conn, ps);//关闭
    }
    @Override
    public List<Map<String, Object>> executeQueryForList(String sql) throws SQLException, ClassNotFoundException {//查询数据
        System.out.println(sql);
        //链接数据库
        Connection conn = RecommenderMysqlImpleDao.getConnection();
        //创建PreparedStatement对象
        PreparedStatement ps=conn.prepareStatement(sql);
        //执行sql语句
        ResultSet rs = ((Statement) ps).executeQuery(sql);
        List<Map<String, Object>> list = rsToList(rs);
        closeConnection(conn, ps, rs);//关闭
        return list;
    }
    @Override
    public Map<String, Object> executeQueryForMap(String sql) throws Exception, SQLException {//获取一条数据
        //链接数据库
        Connection conn = RecommenderMysqlImpleDao.getConnection();
        //创建PreparedStatement对象
        PreparedStatement ps=conn.prepareStatement(sql);
        //执行sql语句
        ResultSet rs = ps.executeQuery(sql);
        List<Map<String, Object>> list=this.rsToList(rs);
        this.closeConnection(conn, ps, rs);
        if (!list.isEmpty())
        {
            return  list.get(0);
        }
        return null;
    }
    @Override
    public int executeQueryForCount(String sql) throws ClassNotFoundException, SQLException {//获取记录数
        //链接数据库
        Connection conn = RecommenderMysqlImpleDao.getConnection();
        //创建PreparedStatement对象
        PreparedStatement ps=conn.prepareStatement(sql);
        //执行sql语句
        ResultSet rs = ps.executeQuery(sql);
        int count = 0;
        if (rs.next()) {
            count = count+rs.getInt(1);
        }
        this.closeConnection(conn, ps, rs);
        return count;
    }
    @Override
    public int executeUpdate(String sql) throws Exception, SQLException {
        System.err.println(sql);

        Connection conn = RecommenderMysqlImpleDao.getConnection();//连接
        PreparedStatement ps=conn.prepareStatement(sql);//创建
        int count = ps.executeUpdate(sql);//执行
        this.releaseConnection(conn, ps);//关闭
        return count;
    }
    private List<Map<String, Object>> rsToList(ResultSet rs) throws SQLException {//将rs转为List<map>
        //初始化list对象
        List<Map<String, Object>> row=new ArrayList<Map<String,Object>>();
        while (rs.next()) {//判断
            //创建map容器
            Map<String, Object> col =new HashMap<String, Object>();
            for (int i=1;i<=rs.getMetaData().getColumnCount();i++) {
                //判断数据类型
                switch (rs.getMetaData().getColumnType(i)) {
                    case Types.VARCHAR:
                        col.put(rs.getMetaData().getColumnName(i), rs.getString(i));
                        break;
                    case Types.INTEGER:
                        col.put(rs.getMetaData().getColumnName(i), rs.getInt(i));
                        break;
                    default:
                        break;
                }
            }
            //添加map数据
            row.add(col);
        }
        return row;
    }
    private void releaseConnection(Connection conn, Statement stmt) throws SQLException {
        try {
            //判断是否为空
            if (stmt!=null)
            {
                stmt.close();
            }
            if (conn!=null)
            {
                conn.close();
            }
        }
        catch (SQLException e)
        {
            throw new SQLException("数据库关闭异常!");
        }
    }
    public void closeConnection(Connection conn, Statement stmt, ResultSet rs) throws SQLException {
        try {
            if (rs!=null) {
                rs.close();
            }
            if (stmt!=null) {
                stmt.close();
            }
            if (conn!=null) {
                conn.close();
            }
        } catch (SQLException e) {
            throw new SQLException("数据关闭异常!");
        }
    }
}
