package interface_;
import entity.PathEntity;
import java.sql.SQLException;
import java.util.List;
import java.util.Map;

public interface PathDao {
    public PathEntity getPath(String id) throws SQLException, ClassNotFoundException;
    public int addPath(String id, String name) throws SQLException, ClassNotFoundException;
    public void delPath(String id) throws SQLException, ClassNotFoundException;

    public List<Map<String, Object>> executeQueryForList(String sql) throws Exception, SQLException;
    public Map<String, Object> executeQueryForMap(String sql) throws Exception, SQLException;
    public int executeQueryForCount(String sql) throws ClassNotFoundException, SQLException;
    public int executeUpdate(String sql) throws Exception, SQLException;

}
