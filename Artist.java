public class Artist {
   private String artistName;
   private int birthYear;
   private int deathYear;

   public Artist() {
      this.artistName = "unknown";
      this.birthYear = -1;
      this.deathYear = -1;
   }
   
   public Artist(String name, int birthYear, int deathYear) {
      this.artistName = name;
      this.birthYear = birthYear;
      this.deathYear = deathYear;
   }
      
   public String getName() {
      return artistName;
   }
   
   public int getBirthYear() {
      return birthYear;
   }
   
   public int getDeathYear() {
      return deathYear;
   }
   
   private String formatYears(int birthYear, int deathYear) {
      if (birthYear == -1)
         return "(unknown)";
      if (deathYear == -1)
         return "(" + birthYear + " to present)";
      return "(" + birthYear + " to " + deathYear + ")";
   }

   public void printInfo() {
      System.out.println(artistName + " " + formatYears(birthYear, deathYear));
   }

}