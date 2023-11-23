package entity;

public class MusicEntity {
    private String id;private String music_name;private String publish_time;private String duration;
    private String type_id;private String player_id;private String recommender_id;private String path_id;
    private float score;private int score_num;

    public  String getId() {return id;}
    public void setId(String id) {this.id = id;}

    public  String getMusic_name() {
        return music_name;
    }
    public void setMusic_name(String music_name) {
        this.music_name = music_name;
    }
    public String getPublish_time() {
        return publish_time;
    }
    public void setPublish_time(String publish_time) {
        this.publish_time = publish_time;
    }
    public String getDuration() {
        return duration;
    }
    public void setDuration(String duration) {
        this.duration = duration;
    }
    public String getPlayer_id() {
        return player_id;
    }
    public void setPlayer_id(String player_id) {
        this.player_id = player_id;
    }
    public String getType_id() {
        return type_id;
    }
    public void setType_id(String type_id) {
        this.type_id = type_id;
    }
    public String getRecommender_id() {
        return recommender_id;
    }
    public void setRecommender_id(String recommender_id) {
        this.recommender_id = recommender_id;
    }
    public float getScore() {
        return score;
    }
    public void setScore(float score) {
        this.score = score;
    }
    public int getScore_num() {
        return score_num;
    }
    public void setScore_num(int score_num) {
        this.score_num = score_num;
    }

    public String getPath_id() {return path_id;}

    public void setPath_id(String path_id) {this.path_id = path_id;}
}
