public class Team {
   
   private String name;
   private int wins;
   private int losses;
   
   public void setName(String name) {
      this.name = name;
   }
   
   public void setWins(int wins) {
      this.wins = wins;
   }
   
   public void setLosses(int losses) {
      this.losses = losses;
   }
   
   public String getName() {
      return name;
   }
   
   public int getWins() {
      return wins;
   }
   
   public int getLosses() {
      return losses;
   }
   
   
   public double getWinPercentage() {
      return (double) wins / (wins + losses);
   }
   
   
   public void printStanding() {
      double winPercent = getWinPercentage();
      System.out.printf("Win percentage: %,.2f\n", winPercent);
      if (winPercent >= 0.5)
         System.out.println("Congratulations, Team " + name + " has a winning average!");
      else
         System.out.println("Team " + name + " has a losing average.");
   }
   
}