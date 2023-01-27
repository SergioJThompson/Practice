public class Artwork {
   private String title;
   private int yearCreated;
   private Artist artist;

   public Artwork() {
      this.title = "unknown";
      this.yearCreated = -1;
      this.artist = new Artist();
   }
   
   public Artwork(String title, int yearCreated, Artist artist) {
      this.title = title;
      this.yearCreated = yearCreated;
      this.artist = artist;
   }

   public String getTitle() {
      return title;
   }
   
   public int getYearCreated() {
      return yearCreated;
   }

   public void printInfo() {
      System.out.print("Artist: ");
      artist.printInfo();
      System.out.println("Title: " + title + ", " + yearCreated);
   }

}
