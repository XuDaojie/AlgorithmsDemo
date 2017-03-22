package io.github.xudaojie;

import edu.princeton.cs.algs4.Bag;
import edu.princeton.cs.algs4.Interval1D;

import java.util.Stack;

/**
 * Created by xdj on 2017/3/18.
 */
public class MainTest {

    public static void main(String[] args) {
//        System.out.println(1 > Double.POSITIVE_INFINITY);
//        System.out.println('b' + 'c'); // char 参与运算时会被转化成int
//        System.out.println('(' + ')');
//        System.out.println(Integer.toBinaryString(127));
//        System.out.println(toBinaryString(127));

//        String string1 = "hello";
//        String string2 = string1;
//        string1 = "world";
//        StdOut.println(string1);
//        StdOut.println(string2);

        Runtime.getRuntime().availableProcessors();

        autoBinPacking();
    }

    /**
     * 讲一个正整数转化为2进制
     *
     * @param i
     * @return
     */
    public static String toBinaryString(int i) {
        String str = "";
        while (i != 1) {
            str = (i % 2) + str;
            i = i / 2;
        }
        return str;
    }

    /**
     * 测试自动装箱
     */
    public static void autoBinPacking() {
        Integer a = 1;
        Integer b = 2;
        Integer c = 3;
        Integer d = 3;
        Integer e = 321;
        Integer f = 321;
        Long g = 3L;
        StdOut.println(c == d);
        StdOut.println(e == f);
        StdOut.println(e == (a + b));
        StdOut.println(c.equals(a + b));
        StdOut.println(g == (a + b));
        StdOut.println(g.equals(a + b));
    }
}
