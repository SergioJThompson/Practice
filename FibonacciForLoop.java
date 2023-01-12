import java.util.Scanner;
import java.util.ArrayList;

public class LabProgram {
   
   public static int fibonacci(int n) {
        if (n < 0) return -1;
        if (n == 0) return 0;
        if (n == 1) return 1;
        int a = 0;
        int b = 1;
        int c = a + b;
        for (int i = 3; i <= n; i++) {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
   }
   
   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);
      int startNum;
      
      startNum = scnr.nextInt();
      System.out.println("fibonacci(" + startNum + ") is " + fibonacci(startNum));
   }
}