package interface_;
import entity.MusicEntity;
import java.sql.SQLException;
import java.util.List;
import java.util.Map;

public interface MusicDao {
    public MusicEntity getMusic(String id) throws SQLException, ClassNotFoundException;
    public int addMusic(MusicEntity music) throws SQLException, ClassNotFoundException;
    public void delMusic(String id) throws SQLException, ClassNotFoundException;
    public static List<Map<String, Object>> executeQueryForList(String sql) throws Exception, SQLException;
    public Map<String, Object> executeQueryForMap(String sql) throws Exception, SQLException;
    public int executeQueryForCount(String sql) throws ClassNotFoundException, SQLException;
    public int executeUpdate(String sql) throws Exception, SQLException;

}
