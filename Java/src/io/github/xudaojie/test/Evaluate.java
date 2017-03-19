package io.github.xudaojie.test;


import io.github.xudaojie.StdIn;
import io.github.xudaojie.StdOut;

import java.util.Stack;

/**
 * Created by xdj on 2017/3/19.
 * 利用栈实现计算器
 * ( 1 + ( ( 2 + 3 ) * ( 4 * 5 ) ) )
 */
public class Evaluate {
    public static void main(String[] args) {
        Stack<Double> vals = new Stack<>();
        Stack<String> ops = new Stack<>();

        while (!StdIn.isEmpty()) {
            String s = StdIn.readString();
            if (s.equals("("));
            else if (s.equals("+")) ops.push(s);
            else if (s.equals("-")) ops.push(s);
            else if (s.equals("*")) ops.push(s);
            else if (s.equals("/")) ops.push(s);
            else if (s.equals(")")) {
                String op = ops.pop();
                double v = vals.pop();
                if (op.equals("+")) v = v + vals.pop();
                else if (op.equals("-")) v = v - vals.pop();
                else if (op.equals("*")) v = v * vals.pop();
                else if (op.equals("/")) v = v / vals.pop();

                vals.push(v);
            }
            else vals.push(Double.parseDouble(s));
        }
        StdOut.println(vals.pop());
    }
}
