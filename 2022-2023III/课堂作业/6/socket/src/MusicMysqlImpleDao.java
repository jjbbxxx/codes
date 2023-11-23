import entity.MusicEntity;
import interface_.MusicDao;

import java.sql.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;



public class MusicMysqlImpleDao implements MusicDao {
    public static String diverName="com.mysql.cj.jdbc.Driver";
    public static String url = "jdbc:mysql://192.168.1.102:3306/shop?useUnicode=true&characterEncoding=UTF-8";
    public static String userName="root";
    public static String password="you235..hedan";
    static Scanner input=new Scanner(System.in);
    public static Connection getConnection() throws ClassNotFoundException, SQLException {
        Class.forName(diverName);//加载
        //指定用户名和密码
        Connection conn = DriverManager.getConnection(url, userName,password);
        return conn;
    }
    @Override
    public MusicEntity getMusic(String id) throws SQLException, ClassNotFoundException {
        String sql="select type_name from music where music_name="+id;
        System.out.println(sql);
        Connection conn = MusicTypeMysqlImpleDao.getConnection();
        //创建Statement对象
        PreparedStatement ps=conn.prepareStatement(sql);
        ResultSet rs = ((Statement) ps).executeQuery(sql);
        List<Map<String, Object>> list = rsToList(rs);
        closeConnection(conn, ps, rs);//关闭
        return (MusicEntity) list;
    }
    @Override
    public int addMusic(MusicEntity music) throws SQLException, ClassNotFoundException {//添加数据
        String sql="insert into music values("+music.getId()+","+music.getMusic_name()+","+ music.getPublish_time()+","+ music.getDuration() +","+ music.getPlayer_id() +","+  music.getType_id()+","+ music.getRecommender_id() +","+ music.getScore() + ","+ music.getScore_num() +")";
        System.out.println(sql);
        Connection conn = MusicMysqlImpleDao.getConnection();//连接
        PreparedStatement ps=conn.prepareStatement(sql);
        int count = ps.executeUpdate(sql);//执行
        this.releaseConnection(conn, ps);//关闭
        return count;
    }
    @Override
    public void delMusic(String id) throws SQLException, ClassNotFoundException {//删除数据
        String sql="delete from music where music_name="+id;
        System.out.println(sql);
        Connection conn = MusicMysqlImpleDao.getConnection();//连接
        PreparedStatement ps=conn.prepareStatement(sql);
        int count = ps.executeUpdate(sql);//执行
        this.releaseConnection(conn, ps);//关闭
    }

    /**
    输入1按作者名，输入2按演奏者，输入3按类型
     */
    public static List<Map<String, Object>> executeQueryForList(String s) throws SQLException, ClassNotFoundException {//查询数据
        String sql = null;
        int a=input.nextInt();
        switch (a){
            case 1:
                sql="select music_id,music_name,duration,type_id,player_id,recommender_id,score,score_num from music where music_name like %s%";
                break;
            case 2:
                sql="select music_id,music_name,duration,type_id,player_id,recommender_id,score,score_num from music where music_player_id like %s%";
                break;
            case 3:
                sql="select music_id,music_name,duration,type_id,player_id,recommender_id,score,score_num from music where type_id like %s%";
                break;
            default:
        }
        System.out.println(sql);
        //链接数据库
        Connection conn = MusicMysqlImpleDao.getConnection();
        //创建PreparedStatement对象
        PreparedStatement ps=conn.prepareStatement(sql);
        //执行sql语句
        ResultSet rs = ((Statement) ps).executeQuery(sql);
        List<Map<String, Object>> list = rsToList(rs);
        closeConnection(conn, ps, rs);//关闭
        return list;
    }
    @Override
    public Map<String, Object> executeQueryForMap(String s) throws Exception, SQLException {//获取一条数据
        String sql = null;
        int a=input.nextInt();
        switch (a){
            case 1:
                sql="select music_id,music_name,duration,type_id,player_id,recommender_id,score,score_num from music where music_name like %s%";
                break;
            case 2:
                sql="select music_id,music_name,duration,type_id,player_id,recommender_id,score,score_num from music where music_player_id like %s%";
                break;
            case 3:
                sql="select music_id,music_name,duration,type_id,player_id,recommender_id,score,score_num from music where type_id like %s%";
                break;
            default:
        }
        //链接数据库
        Connection conn = MusicMysqlImpleDao.getConnection();
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
    public int executeQueryForCount(String s) throws ClassNotFoundException, SQLException {//获取记录数
        String sql = null;
        int a=input.nextInt();
        switch (a){
            case 1:
                sql="select music_id,music_name,duration,type_id,player_id,recommender_id,score,score_num from music where music_name like %s%";
                break;
            case 2:
                sql="select music_id,music_name,duration,type_id,player_id,recommender_id,score,score_num from music where music_player_id like %s%";
                break;
            case 3:
                sql="select music_id,music_name,duration,type_id,player_id,recommender_id,score,score_num from music where type_id like %s%";
                break;
            default:
        }
        //链接数据库
        Connection conn = MusicMysqlImpleDao.getConnection();
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

        Connection conn = MusicMysqlImpleDao.getConnection();//连接
        PreparedStatement ps=conn.prepareStatement(sql);//创建
        int count = ps.executeUpdate(sql);//执行
        this.releaseConnection(conn, ps);//关闭
        return count;
    }
    public static int score(String id, int s) throws SQLException, ClassNotFoundException {//每个人只能打一次分
        String sql="update music set score=(score*score_num+"+s+")/(score_num+1),score_name=score_name+1 where music_id="+id;//score表示平均分数
        Connection conn = MusicMysqlImpleDao.getConnection();//连接
        PreparedStatement ps=conn.prepareStatement(sql);
        int count = ps.executeUpdate(sql);//执行
        this.releaseConnection(conn, ps);//关闭
        return count;
    }
    private static List<Map<String, Object>> rsToList(ResultSet rs) throws SQLException {//将rs转为List<map>
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
    private void releaseConnection(Connection conn, PreparedStatement ps) throws SQLException {
        try {
            //判断是否为空
            if (ps!=null)
            {
                ps.close();
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
    public static void closeConnection(Connection conn, PreparedStatement ps, ResultSet rs) throws SQLException {
        try {
            if (rs!=null) {
                rs.close();
            }
            if (ps!=null) {
                ps.close();
            }
            if (conn!=null) {
                conn.close();
            }
        } catch (SQLException e) {
            throw new SQLException("数据关闭异常!");
        }
    }
}
