package io.github.xudaojie.test;

import io.github.xudaojie.In;
import io.github.xudaojie.StdOut;

/**
 * Created by xdj on 2017/3/19.
 * 1.4.2.1
 * java ThreeSum 1Kints.txt
 */
public class ThreeSum {
    public static int count(int[] a) {
        // 统计和为0的元组数量
        int N = a.length;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    if (a[i] + a[j] + a[k] == 0) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        In in = new In(args[0]);
        int[] a = in.readAllInts();
        StdOut.println(count(a));
    }
}
