package com.company;

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {
    public int[] moveValue(int[] array, int value){
        int j = 0, pos = 0, temp;
        for (int i = 0; i < array.length; i++) {
            if (array[i] != value){
                pos = i;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                j++;
            }
        }
        for (int i = pos + 1; i < array.length; i++) {
            array[i] = value;
        }
        return array;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String sin = sc.nextLine().replaceAll("\\[|\\]", "");
        int value = sc.nextInt();
        String[] s = sin.split(", ");;
        int[] arr = new int[s.length];
        if (s.length == 1 && s[0].isEmpty())
            arr = new int[]{};
        else {
            for(int i = 0; i < s.length; ++i)
                arr[i] = Integer.parseInt(s[i]);
        }
        int[] res = new Main().moveValue(arr, value);
        System.out.print("[");
        for(int i = 0; i < res.length; ++i) {
            System.out.print(res[i]);
            if(i != res.length - 1)
                System.out.print(", ");
        }
        System.out.print("]");
    }
}
