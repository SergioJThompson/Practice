import java.util.Scanner;
import java.util.Random;

public class LabProgram {
   
   public static String coinFlip(Random rand) {
      int result = rand.nextInt(2);
      if (result == 1) return "Heads";
      return "Tails";
   }
   
   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);
      Random rand = new Random(2); // Seed used in develop mode
      int flips = scnr.nextInt();
      for (int i = 0; i < flips; i++)
         System.out.println(coinFlip(rand));
   }
}
