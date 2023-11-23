import interface_.PathDao;

public class test {
    public static void main(String[] args) throws Exception
    {
        PathDao dao = new PathMysqlImpleDao();
        String sql = " select * from path where path_id='100' ";
        String sql1="INSERT INTO PATH(path_id,path_name) VALUES(100,'A')";
        dao.addPath("200","bb");

//        List<Map<String, Object>> list = dao.executeQueryForList(sql);
//        for (Map<String, Object> map : list) {
//            System.out.println(map);
//        }
//        int count = dao.executeUpdate(sql1);
//        System.out.println(count!=0?"运行成功!":"运行失败!");

    }
}
