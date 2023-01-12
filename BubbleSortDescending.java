import java.util.Scanner;
import java.util.Arrays;

public class LabProgram {

    public static void sortArray(int[] myArr, int arrSize) {
        for (int i = 0; i < arrSize; i++)
            bubbleSortPass(myArr);
    }

    private static void bubbleSortPass(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            int a = arr[i];
            int b = arr[i+1];
            if (a < b)
                swapIndexes(arr, i, i+1);
        }
    }

    private static void swapIndexes(int[] arr, int i, int j) {
        int placeholder = arr[i];
        arr[i] = arr[j];
        arr[j] = placeholder;
    }

    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);
        int size = scnr.nextInt();
        int[] arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = scnr.nextInt();
        sortArray(arr, size);
        for (int j : arr) System.out.print(j + ",");
        System.out.println();
    }
}
