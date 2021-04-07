package com.company;

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {
    public int[] sumEvenOdd(int[] array){
        int sumEven = 0, sumOdd = 0;
        if (array.length == 0){
            sumEven = 0;
            sumOdd = 0;
        } else {
            for (int i = 0; i < array.length; i++) {
                if (array[i] % 2 == 0) {
                    sumEven += array[i];
                } else {
                    sumOdd += array[i];
                }
            }
        }
        int[] result = new int[] {sumEven, sumOdd};
        return result;
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
        int[] res = new Main().sumEvenOdd(arr);
        System.out.print("[");
        for(int i = 0; i < res.length; ++i) {
            System.out.print(res[i]);
            if(i != res.length - 1)
                System.out.print(", ");
        }
        System.out.print("]");
    }
}
