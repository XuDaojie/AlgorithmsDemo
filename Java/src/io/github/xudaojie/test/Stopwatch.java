package io.github.xudaojie.test;

import io.github.xudaojie.StdOut;
import io.github.xudaojie.StdRandom;

/**
 * Created by xdj on 2017/3/19.
 * 1.4.2.2
 */
public class Stopwatch {

    private final long start;

    public Stopwatch() {
        start = System.currentTimeMillis();
    }

    public double elapsedTime() {
        return (System.currentTimeMillis() - start) / 1000;
    }

    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        int[] a = new int[N];

        for (int i = 0; i < N; i++) {
            a[i] = StdRandom.uniform(-100000, 100000);
        }
        Stopwatch timer = new Stopwatch();
        int cnt = ThreeSum.count(a);
        StdOut.println(cnt + " triples " + timer.elapsedTime() + "seconds");
    }
}
