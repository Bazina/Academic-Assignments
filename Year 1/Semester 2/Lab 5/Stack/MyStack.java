import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

interface IStack {

    /*** Removes the element at the top of stack and returns that element.
     * @return top of stack element, or through exception if empty
     */

    Object pop() throws EmptyStackException;

    /*** Get the element at the top of stack without removing it from stack.
     * @return top of stack element, or through exception if empty
     */

    Object peek() throws EmptyStackException;

    /*** Pushes an item onto the top of this stack.
     * @param element to insert*
     */

    void push(Object element) throws StackOverflowError;

    /*** Tests if this stack is empty
     * @return true if stack empty
     */

    boolean isEmpty();

    int size();
}

class Node {
    Object data;
    Node next;

    Node(Object value) {
        data = value;
        next = null;
    }
}

class Stack implements IStack {
    Node top = null;
    private int size = 0;

    public Object pop() {
        if (!isEmpty()) {
            int popTop = (int) top.data;
            top = top.next;
            size--;
            return popTop;
        }
        throw new EmptyStackException();
    }

    public Object peek() {
        if (!isEmpty()) {
            return top.data;
        }
        throw new EmptyStackException();
    }

    public void push(Object element) {
        Node n = new Node(element);
        n.next = top;
        top = n;
        size++;
    }

    public boolean isEmpty() {
        return top == null;
    }

    public int size() {
        return size;
    }

    public void print() {
        System.out.print("[");
        while (top != null) {
            if (top.next != null) {
                System.out.print(top.data + ", ");
            } else {
                System.out.print(top.data);
            }
            top = top.next;
        }
        System.out.print("]");
    }
}

public class MyStack {

    public static void main(String[] args) {
        Stack stack = new Stack();
        Scanner sc = new Scanner(System.in);
        String sin = sc.nextLine().replaceAll("[\\[\\]]", "");
        String[] newS = sin.split(", ");
        int[] arr = new int[newS.length];
        if (!(newS.length == 1 && newS[0].isEmpty())) {
            for (int i = 0; i < newS.length; i++) {
                arr[i] = Integer.parseInt(newS[i]);
            }
            for (int i = 0; i < arr.length; i++) {
                stack.push(arr[arr.length - 1 - i]);
            }
        }
        String opr = sc.next();
        try {
            switch (opr) {
                case "push":
                    int num = sc.nextInt();
                    stack.push(num);
                    stack.print();
                    break;

                case "pop":
                    stack.pop();
                    stack.print();
                    break;

                case "peek":
                    System.out.println(stack.peek());
                    break;

                case "size":
                    System.out.println(stack.size());
                    break;

                case "isEmpty":
                    if (stack.isEmpty()) {
                        System.out.println("True");
                    } else {
                        System.out.println("False");
                    }
                    break;
            }
        } catch (EmptyStackException e) {
            System.out.println("Error");
        }
    }
}