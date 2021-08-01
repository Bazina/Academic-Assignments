import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {
    public int fibonacci(int n) {
        int fibTerm = 0, fib1 = 1, fib2 = 1;
        for (int i = 1; i < n; i++) {
            fib2 = fib1 + fibTerm;
            fibTerm = fib1;
            fib1 = fib2;
        }
        return fibTerm;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int term = new Main().fibonacci(n);
        System.out.println(term);
    }
}
