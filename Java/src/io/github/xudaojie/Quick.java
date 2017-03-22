package io.github.xudaojie;

import java.util.Comparator;

/**
 * Created by xdj on 2017/3/22.
 * 快速排序
 */
public class Quick {

    public static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

    public static void exch(Comparable[] a, int i, int j) {
        Comparable tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    /**
     * 将数组切分为两段，左端<=返回值，右端>=返回值
     * @param a
     * @return j
     */
    public static int partition(Comparable[] a, int lo, int hi) {
        int i = lo, j = hi + 1;
        Comparable v = a[lo];

        while (true) {
            while (less(a[++i], v)) {
                if (i == hi) break;
            }
            while (less(v, a[--j])) {
                if (j == lo) break;
            }
            if (i >= j) break;
            exch(a, i, j);
        }
        exch(a, lo, j);
        return j;
    }

    public static void sort(Comparable[] a) {
        sort(a, 0, a.length - 1);
    }

    private static void sort(Comparable[] a, int lo, int hi) {
        if (hi <= lo) return;

        int k = partition(a, lo, hi);
        sort(a, lo, k - 1);
        sort(a, k + 1,  hi);
    }

    public static void main(String[] args) {
        Integer[] a = new Integer[] {5, 1, 2, 11, 32, 4, 56, 3};
        sort(a);

        for (int i = 0; i < a.length; i++) {
            StdOut.print(a[i] + " ");
        }
    }
}
