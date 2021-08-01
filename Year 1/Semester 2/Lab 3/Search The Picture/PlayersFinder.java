import java.awt.*;
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.List;
import java.util.regex.*;


interface IPlayersFinder {
    /**
     * Search for players locations at the given photo
     * @param photo
     *     Two dimension array of photo contents
     *     Will contain between 1 and 50 elements, inclusive
     * @param team
     *     Identifier of the team
     * @param threshold
     *     Minimum area for an element
     *     Will be between 1 and 10000, inclusive
     * @return
     *     Array of players locations of the given team
     */
    List<Point> findPlayers(String[] photo, int team, int threshold);
}

public class PlayersFinder implements IPlayersFinder{
    public int find (int start_i, int start_j, int[][] arr_check) {
        int area = 4;
        Point first, last;
        first = new Point(start_j * 2, start_i * 2);
        last = new Point((start_j * 2) + 2, (start_i * 2) + 2);
        if (start_j + 1 < arr_check[0].length && arr_check[start_i][start_j + 1] == 1) {
            last.x = 2 * (start_j + 1) + 2;
            if (maxX < last.x) {
                maxX = last.x;
            }
            arr_check[start_i][start_j + 1] = -1;
            area += find(start_i, start_j + 1, arr_check);
        }
        if (start_j > 0 && arr_check[start_i][start_j - 1] == 1) {
            first.x = 2 * (start_j - 1);
            if (minX > first.x) {
                minX = first.x;
            }
            arr_check[start_i][start_j - 1] = -1;
            area += find(start_i, start_j - 1, arr_check);
        }
        if (start_i > 0 && arr_check[start_i - 1][start_j] == 1) {
            first.y = 2 * (start_i - 1);
            if (minY > first.y) {
                minY = first.y;
            }
            arr_check[start_i - 1][start_j] = -1;
            area += find(start_i - 1, start_j, arr_check);
        }
        if (start_i + 1 < arr_check.length && arr_check[start_i + 1][start_j] == 1) {
            last.y = 2 * (start_i + 1) + 2;
            if (maxY < last.y) {
                maxY = last.y;
            }
            arr_check[start_i + 1][start_j] = -1;
            area += find(start_i + 1, start_j, arr_check);
        }
        return area;
    }
    public List<Point> findPlayers(String[] photo, int team, int threshold) {
        List<Point> centers = new ArrayList<Point>();
        int row = photo.length, col = photo[0].length(), area = 0;
        char teamC = (char)(team + '0');
        int[][] arr_check = new int[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (photo[i].charAt(j) == teamC) {
                    arr_check[i][j] = 1;
                } else {
                    arr_check[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (arr_check[i][j] == 1) {
                    arr_check[i][j] = -1;
                    minY = i * 2;
                    minX = j * 2;
                    maxY = (i * 2) + 2;
                    maxX = (j * 2) + 2;
                    area = find(i, j, arr_check);
                    if (area < threshold) continue;
                    if (maxY < ((i * 2) + 2)) {
                        maxY = i * 2;
                    }
                    if (maxX < ((j * 2) + 2)) {
                        maxX = j * 2;
                    }
                    if (minX > (j * 2)) {
                        minX = j * 2;
                    }
                    if (minY > (i * 2)) {
                        minY = i * 2;
                    }
                    centers.add(new Point((maxX + minX)/2, (maxY + minY)/2));
                }
            }
        }
        return centers;
    }

    static int maxX = 0, maxY = 0, minX = 0, minY = 0;

    public static void main(String[] args) {
        int r, c, team, thres;
        Scanner sc = new Scanner(System.in);
        String rc = sc.nextLine();
        String[] rc_new = rc.split(", ");
        r = Integer.parseInt(rc_new[0]);
        c = Integer.parseInt(rc_new[1]);
        String[] photo = new String[r];
        for (int i = 0; i < r; i++) {
            photo[i] = sc.nextLine();
        }
        team = sc.nextInt();
        thres = sc.nextInt();
        List<Point> res = new PlayersFinder().findPlayers(photo, team, thres);
        Collections.sort(res, new Comparator<Point>() {
            public int compare(Point o1, Point o2) {
                if (o1.getX() != o2.getX()) {
                    return Integer.compare((int) o1.getX(), (int) o2.getX());
                } else {
                    return Integer.compare((int) o1.getY(), (int) o2.getY());
                }
            }
        });
        System.out.print("[");
        for (int i = 0; i < res.size(); i++) {
            if (i < res.size() - 1) {
                System.out.print("(" + res.get(i).x + ", " + res.get(i).y + ")" + ", ");
            } else {
                System.out.print("(" + res.get(i).x + ", " + res.get(i).y + ")");
            }
        }
        System.out.print("]");
    }
}