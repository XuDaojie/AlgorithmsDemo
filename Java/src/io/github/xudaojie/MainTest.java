package io.github.xudaojie;

/**
 * Created by xdj on 2017/3/18.
 */
public class MainTest {
    public static void main(String[] args) {
        System.out.println(1 > Double.POSITIVE_INFINITY);
        System.out.println('b' + 'c'); // char 参与运算时会被转化成int
        System.out.println('(' + ')');
        System.out.println(Integer.toBinaryString(127));
        System.out.println(toBinaryString(127));
    }

    /**
     * 讲一个正整数转化为2进制
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
}
