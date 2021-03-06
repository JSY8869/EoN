package Seventh_java;

class DB{

    private String title;
    private String author;
    private String year;
    private String company;
    private String genre;

    public DB(String title, String author, String year, String company, String genre) {
        this.title = title;
        this.author = author;
        this.year = year;
        this.company = company;
        this.genre = genre;
    }
    public void setter(String title, String author, String year, String company, String genre){
        this.title = title;
        this.author = author;
        this.year = year;
        this.company = company;
        this.genre = genre;
    }
    public String getTitle() {
        return this.title;
    }
    public String getAuthor() {
        return this.author;
    }
    public String getYear() {
        return this.year;
    }
    public String getCompany() {
        return this.company;
    }
    public String getGenre() {
        return this.genre;
    }
    public void show(){
        System.out.println(this.title + " " + this.author + " " + this.year + " " + this.company + " " + this.genre);
    }
}