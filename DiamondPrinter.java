import java.util.ArrayList;
import java.util.List;

class DiamondPrinter {

    List<String> printToList(char middle_ch) {
        List<String> rows = rowsFromStartUntil(middle_ch);
        rows.addAll(rowsFromMiddleChToEnd(middle_ch));
        return rows;
    }

    List<String> rowsFromStartUntil(char middle_ch) {
        List<String> rows = new ArrayList<>();
        for (char this_ch = 'A'; this_ch < middle_ch; this_ch++)
            rows.add(row(this_ch, middle_ch));
        return rows;
    }

    List<String> rowsFromMiddleChToEnd(char middle_ch) {
        List<String> rows = new ArrayList<>();
        for (char this_ch = middle_ch; this_ch >= 'A'; this_ch--)
            rows.add(row(this_ch, middle_ch));
        return rows;
    }

    String row(char this_ch, char middle_ch) {
        String spacesBeforeOrAfterCh = get_spaces(numOfSpacesBeforeOrAfterCh(this_ch, middle_ch));
        if (this_ch == 'A') return spacesBeforeOrAfterCh + this_ch + spacesBeforeOrAfterCh;
        String spacesBetweenInstancesOfCh = get_spaces(numOfSpacesBetweenInstancesOfCh(this_ch));
        return spacesBeforeOrAfterCh + this_ch + spacesBetweenInstancesOfCh + this_ch + spacesBeforeOrAfterCh;
    }

    int numOfSpacesBeforeOrAfterCh(char this_ch, char middle_ch) {
        return distanceBetween(this_ch, middle_ch);
    }

    int numOfSpacesBetweenInstancesOfCh(char ch) {
        return 2 * distanceBetween(ch, 'A') - 1;
    }

    int distanceBetween(char ch1, char ch2) {
        return Math.abs(ch1 - ch2);
    }

    String get_spaces(int numOfSpaces) {
        return " ".repeat(numOfSpaces);
    }

}
