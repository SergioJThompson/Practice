import java.io.*;
import java.util.Scanner;

class Main {
    public static void main(String[] args) throws IOException {
        Scanner scnr = new Scanner(System.in);
        String filename = "";

        String line = "";
        String currentMovie = "";
        String movieTitle = "";
        String movieRating = "";
        StringBuilder movieShowtimes = new StringBuilder();

        BufferedReader inputReader = new BufferedReader(new InputStreamReader(System.in));
        filename = scnr.next();

        BufferedReader reader = new BufferedReader(new FileReader(filename));
        while ((line = reader.readLine()) != null) {
            String[] movieInfo = line.split(",");
            if (!currentMovie.equals(movieInfo[1])) {
                if (!currentMovie.equals(""))
                    System.out.printf("%-44s |%5s | %s\n", movieTitle.substring(0, Math.min(movieTitle.length(), 44)), movieRating, movieShowtimes);
                currentMovie = movieInfo[1];
                movieTitle = movieInfo[1];
                movieRating = movieInfo[2];
                movieShowtimes = new StringBuilder(movieInfo[0]);
            } else
                movieShowtimes.append(" ").append(movieInfo[0]);
        }
        System.out.printf("%-44s |%5s | %s\n", movieTitle.substring(0, Math.min(movieTitle.length(), 44)), movieRating, movieShowtimes);
    }
}


