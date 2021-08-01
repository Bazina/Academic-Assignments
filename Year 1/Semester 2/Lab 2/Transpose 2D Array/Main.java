import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {
    public int[][] transpose(int[][] array){
        int[][] trans = new int[array.length][array.length];
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length; j++) {
                trans[j][i] = array[i][j];
            }
        }
        return trans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String sin = sc.nextLine().replaceAll("\\[|\\]", "");
        String[] s = sin.split(", ");
        int n = (int)Math.sqrt(s.length), k = 0;
        int[][] arr = new int[n][n];
        if (s.length == 1 && s[0].isEmpty())
            arr = new int[][]{};
        else {
            for(int i = 0; i < n; ++i){
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(s[k]);
                    k++;
                }
            }
        }
        int[][] res = new Main().transpose(arr);
        if (arr.length > 0) {
            System.out.print("[");
            int i, j;
            for (i = 0; i < res.length; ++i) {
                System.out.print("[");
                for (j = 0; j < n; j++) {
                    System.out.print(res[i][j]);
                    if (j != res.length - 1) {
                        System.out.print(", ");
                    }
                }
                System.out.print("]");
                if (i == n - 1) {

                } else {
                    System.out.print(", ");
                }
            }
            System.out.print("]");
        } else {
            System.out.println("[[]]");
        }
    }
}
