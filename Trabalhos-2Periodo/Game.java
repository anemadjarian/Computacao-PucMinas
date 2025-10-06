import java.util.*;
public class Game{
    int id;
    String name;
    String releaseDate;
    int estimatedOwners;
    float price;
    String[] supportedLangueges = new String[50];
    int metacriticScore;
    int userScore;
    int achievements;
    String publishers;
    String developers;
    String[] categories = new String[50];
    String[] genres = new String[50];
    String[] tags = new String[50];

    public int getAchievements() {
        return achievements;
    }
    public String[] getCategories() {
        return categories;
    }
    public String getDevelopers() {
        return developers;
    }
    public int getEstimatedOwners() {
        return estimatedOwners;
    }
    public String[] getGenres() {
        return genres;
    }
    public int getId() {
        return id;
    }
    public int getMetacriticScore() {
        return metacriticScore;
    }
    public String getName() {
        return name;
    }
    public float getPrice() {
        return price;
    }
    public String getPublishers() {
        return publishers;
    }
    public String getReleaseDate() {
        return releaseDate;
    }
    public String[] getSupportedLangueges() {
        return supportedLangueges;
    }
    public String[] getTags() {
        return tags;
    }
    public int getUserScore() {
        return userScore;
    }

    public void setAchievements(int achievements) {
        this.achievements = achievements;
    }
    public void setCategories(String[] categories) {
        this.categories = categories;
    }
    public void setDevelopers(String developers) {
        this.developers = developers;
    }
    public void setEstimatedOwners(int estimatedOwners) {
        this.estimatedOwners = estimatedOwners;
    }
    public void setGenres(String[] genres) {
        this.genres = genres;
    }
    public void setId(int id) {
        this.id = id;
    }
    public void setMetacriticScore(int metacriticScore) {
        this.metacriticScore = metacriticScore;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setPrice(float price) {
        this.price = price;
    }
    public void setPublishers(String publishers) {
        this.publishers = publishers;
    }
    public void setReleaseDate(String releaseDate) {
        this.releaseDate = releaseDate;
    }
    public void setSupportedLangueges(String[] supportedLangueges) {
        this.supportedLangueges = supportedLangueges;
    }
    public void setTags(String[] tags) {
        this.tags = tags;
    }
    public void setUserScore(int userScore) {
        this.userScore = userScore;
    }

    public static void main(String[] args){
        
    }
}