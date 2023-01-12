import java.util.Scanner;

public class LabProgram {
      
   public static void swapValues(int[] values) {
      swapAtIndexes(values, 0, 1);
      swapAtIndexes(values, 2, 3);
   }
   
   public static void swapAtIndexes(int[] values, int i, int j) {
      int placeholder = values[i];
      values[i] = values[j];
      values[j] = placeholder;
   }
   
   public static void print(int[] values) {
      String s = "";
      for (int i = 0; i < values.length; i++)
         s += values[i] + " ";
      System.out.println(s.substring(0, s.length() - 1));
   }

   
   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);
      int[] values = new int[]{scnr.nextInt(), scnr.nextInt(), scnr.nextInt(), scnr.nextInt()};
      swapValues(values);
      print(values);
   }
}
