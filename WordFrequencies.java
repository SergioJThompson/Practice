import java.util.Scanner;

public class LabProgram {

    public static int getWordFrequency(String[] wordsList, int listSize, String currWord) {
        int freq = 0;
        for (String word : wordsList) {
            if (word.equalsIgnoreCase(currWord))
                freq++;
        }
        return freq;
    }


    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);
        int size = scnr.nextInt();
        String[] words = scnr.nextLine().substring(1).split(" ");
        for (String word : words)
            System.out.println(word + " " + getWordFrequency(words, size, word));
    }
}
