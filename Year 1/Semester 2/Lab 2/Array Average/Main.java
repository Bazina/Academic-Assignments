package com.company;

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {
    public double average(int[] array){
        double sum = 0;
        if (array.length == 0){
            sum = 0.0;
        } else {
            for (int i = 0; i < array.length; i++) {
                sum += array[i];
            }
            sum /= array.length;
        }
        return sum;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String sin = sc.nextLine().replaceAll("\\[|\\]", "");
        String[] s = sin.split(", ");;
        int[] arr = new int[s.length];
        if (s.length == 1 && s[0].isEmpty())
            arr = new int[]{};
        else {
            for(int i = 0; i < s.length; ++i)
                arr[i] = Integer.parseInt(s[i]);
        }
        double res = new Main().average(arr);
        System.out.print(res);
    }
}
