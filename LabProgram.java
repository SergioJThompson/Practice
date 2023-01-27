import java.util.Scanner;

public class LabProgram {
   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);
      int purchase = scnr.nextInt();
      int restock = scnr.nextInt();
      VendingMachine vm = new VendingMachine();
      vm.purchase(purchase);
      vm.restock(restock);
      vm.report();
   }
}
