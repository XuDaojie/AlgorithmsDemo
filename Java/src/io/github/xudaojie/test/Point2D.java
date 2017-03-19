package io.github.xudaojie.test;

import io.github.xudaojie.StdDraw;
import io.github.xudaojie.StdRandom;

import java.awt.*;

public final class Point2D {
    private double x = 0.0;
    private double y = 0.0;

    public Point2D(double x, double y) {
        if (Double.isInfinite(x) || Double.isInfinite(y))
            throw new IllegalArgumentException("Coordinates must be finite");
        if (Double.isNaN(x) || Double.isNaN(y))
            throw new IllegalArgumentException("Coordinates cannot be NaN");

        this.x = x;
        this.y = y;
    }

    public void draw() {
        StdDraw.point(x, y);
    }

    public void drawTo(Point2D point) {
        StdDraw.line(x, y, point.getX(), point.getY());
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public static void main(String[] args) {
        int x0 = Integer.parseInt(args[0]);
        int y0 = Integer.parseInt(args[1]);
        int n = Integer.parseInt(args[2]);

        StdDraw.setCanvasSize(800, 800);
        StdDraw.setXscale(0, 100);
        StdDraw.setYscale(0, 100);
        StdDraw.setPenRadius(.005f);
        StdDraw.setPenColor(Color.BLACK);
//        StdDraw.enableDoubleBuffering();

        // 画随机点
        Point2D[] points = new Point2D[n];
        for (int i = 0; i < n; i++) {
            int x = StdRandom.uniform(100);
            int y = StdRandom.uniform(100);
            points[i] = new Point2D(x, y);
            points[i].draw();
        }

        // 画点
        StdDraw.setPenRadius(0.01f);
        StdDraw.setPenColor(Color.RED);
        Point2D p = new Point2D(x0 , y0);
        p.draw();

        // 画线
        StdDraw.setPenRadius();
        StdDraw.setPenColor(Color.BLUE);
        for (int i = 0; i < n; i++) {
            p.drawTo(points[i]);
            StdDraw.pause(50);
        }
    }
}
