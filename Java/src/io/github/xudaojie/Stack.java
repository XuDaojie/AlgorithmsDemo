package io.github.xudaojie;

/**
 * Created by xdj on 2017/3/19.
 */
public class Stack<E> {

    private Node<E> first;
    private int n; // size

    public void push(E element) {
        Node<E> oldFirst = first;
        first = new Node<>();
        first.element = element;
        first.next = oldFirst;

        ++n;
    }

    public Node<E> pop() {
        if (!isEmpty()) {
            Node<E> oldFirst = first;
            first = oldFirst.next;
            --n;
            return oldFirst;
        }
        return null;
    }

    public boolean isEmpty() {
        return first == null;
    }

    public int size() {
        return n;
    }

    private static class Node<E> {
        private E element;
        private Node<E> next;
    }
}
