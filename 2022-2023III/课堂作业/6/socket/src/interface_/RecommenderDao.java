package interface_;
import entity.RecommenderEntity;
import java.sql.SQLException;
import java.util.List;
import java.util.Map;

public interface RecommenderDao {
    public RecommenderEntity getRecommender(String id) throws SQLException, ClassNotFoundException;
    public int addRecommender(String id, String name) throws SQLException, ClassNotFoundException;
    public void delRecommender(String id) throws SQLException, ClassNotFoundException;
    public List<Map<String, Object>> executeQueryForList(String sql) throws Exception, SQLException;
    public Map<String, Object> executeQueryForMap(String sql) throws Exception, SQLException;
    public int executeQueryForCount(String sql) throws ClassNotFoundException, SQLException;
    public int executeUpdate(String sql) throws Exception, SQLException;

}
