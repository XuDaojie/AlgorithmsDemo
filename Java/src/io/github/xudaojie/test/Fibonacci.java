package io.github.xudaojie.test;

import edu.princeton.cs.algs4.StdOut;

/**
 * Created by xdj on 2017/3/18.
 * 1.1.19
 * https://segmentfault.com/q/1010000003012206
 */
public class Fibonacci {
    public static long F(int N) {
        if (N == 0) return 0;
        if (N == 1) return 1;
        return F(N - 1) + F(N - 2);
    }

    public static long Fib(int N) {
        long[] f = new long[N + 1];
        return Fib(N, f);
    }

    public static long Fib(int N, long[] f) {
        if (f[N] == 0) {
            if (N == 1)
                f[N] = 1;
            else if (N > 1)
                f[N] = Fib(N - 1, f) + Fib(N - 2, f);
        }
        return f[N];
    }

    public static void main(String[] args) {
        // 存在重复计算的问题
//        for (int N = 0; N < 100; N++)
//            StdOut.println(N + " " + F(N));

        for (int N = 0; N < 100; N++)
            StdOut.println(N + " " + Fib(N));
    }
}
