package io.github.xudaojie;

import java.util.Comparator;

/**
 * Created by xdj on 2017/3/22.
 * 插入排序
 */
public class Insertion {

    public static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

    public static void exch(Comparable[] a, int i, int j) {
        Comparable tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    public static void sort(Comparable[] a) {
        int N = a.length;

        for (int i = 1; i < N; i++) {
            for (int j = i; j > 0 && less(a[j], a[j - 1]); j--) {
                exch(a, j, j - 1);
            }
        }
    }

    public static void main(String[] args) {
        Integer[] integers = new Integer[] {5, 1, 2, 11, 32, 4, 56, 3};
        sort(integers);
        for (Integer i :
                integers) {
            StdOut.print(i + ",");
        }
        StdOut.println();
    }
}
