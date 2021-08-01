import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

interface IExpressionEvaluator {

    /**
     * Takes a symbolic/numeric infix expression as input and converts it to
     * postfix notation. There is no assumption on spaces between terms or the
     * length of the term (e.g., two digits symbolic or numeric term)
     *
     * @param expression infix expression
     * @return postfix expression
     */

    String infixToPostfix(String expression);


    /**
     * Evaluate a postfix numeric expression, with a single space separator
     *
     * @param expression postfix expression
     * @return the expression evaluated value
     */

    int evaluate(String expression);

}

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
            Object popTop = top.data;
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

public class Evaluator implements IExpressionEvaluator {

    static int a, b, c, d = 0;
    static Evaluator eval = new Evaluator();

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String expr = sc.next();
        for (int i = 0; i < 3; i++) {
            String sin = sc.next();
            String[] newS = sin.split("=");
            switch (sin.charAt(0)) {
                case 'a': {
                    a = Integer.parseInt(newS[1]);
                    break;
                }
                case 'b': {
                    b = Integer.parseInt(newS[1]);
                    break;
                }
                case 'c': {
                    c = Integer.parseInt(newS[1]);
                    break;
                }
            }
        }

        if (expr.startsWith("--")) {
            expr = expr.replaceFirst("--", "");
        }
        if (!(expr.startsWith("--")) && (expr.contains("*--") || expr.contains("/--") || expr.contains("^--"))) {
            expr = expr.replaceAll("--", "");
        }
        if (!(expr.startsWith("--")) && expr.contains("--")) {
            expr = expr.replaceAll("--", "+");
        }
        try {
            String postExpr = eval.infixToPostfix(expr);
            int evaluation = eval.evaluate(postExpr);
            System.out.println(postExpr);
            System.out.println(evaluation);
        } catch (Exception e) {
            System.out.println("Error");
        }
    }

    public int GetOperatorWeight(char op) {
        int weight = -1;
        switch (op) {
            case '+':
            case '-':
                weight = 1;
                break;
            case '*':
            case '/':
                weight = 2;
                break;
            case '^':
                weight = 3;
                break;
        }
        return weight;
    }

    public boolean Precedence(char opr1, char opr2) {
        int oprWeight1 = GetOperatorWeight(opr1);
        int oprWeight2 = GetOperatorWeight(opr2);
        if (oprWeight2 == oprWeight1) {
            if (opr1 == opr2) {
                return true;
            }
        }
        return oprWeight1 >= oprWeight2;
    }

    public boolean checkChar(Stack test) {
        if (test.top.data == (Object) 'a') return true;
        else if (test.top.data == (Object) 'b') return true;
        else if (test.top.data == (Object) 'c') return true;
        else if (test.top.data == (Object) 'd') return true;
        return false;
    }

    public boolean checkOpr(String test, int i) {
        if (test.charAt(i) == '+') return false;
        else if (test.charAt(i) == '-') return false;
        else if (test.charAt(i) == '*') return false;
        else if (test.charAt(i) == '/') return false;
        else if (test.charAt(i) == '^') return false;
        return true;
    }

    public String infixToPostfix(String expression) {
        Stack postOpr = new Stack();
        int paren = 0;
        String postExpr = "";
        try {
            for (int i = 0; i < expression.length(); i++) {
                if (expression.charAt(i) == 'a' || expression.charAt(i) == 'b' || expression.charAt(i) == 'c') {
                    switch (expression.charAt(i)) {
                        case 'a':
                            postExpr += "a";
                            break;
                        case 'b':
                            postExpr += "b";
                            break;
                        case 'c':
                            postExpr += "c";
                            break;
                    }
                } else if (expression.charAt(i) == '+'
                        || expression.charAt(i) == '-'
                        || expression.charAt(i) == '/'
                        || expression.charAt(i) == '*'
                        || expression.charAt(i) == '^') {
                    while (!postOpr.isEmpty() && (char) postOpr.top.data != '(' &&
                            Precedence((char) postOpr.top.data, expression.charAt(i))) {
                        postExpr += ((char) postOpr.top.data);
                        postOpr.pop();
                    }
                    postOpr.push(expression.charAt(i));

                    if (expression.charAt(i + 1) == '-' && (expression.charAt(i) == '*' || expression.charAt(i) == '/' || expression.charAt(i) == '^')) {
                        postOpr.push(expression.charAt(i + 1));
                        postExpr += 'd';
                        i++;
                    }

                } else if (expression.charAt(i) == '(') {
                    paren++;
                    postOpr.push(expression.charAt(i));
                } else if (expression.charAt(i) == ')') {
                    paren--;
                    while (!postOpr.isEmpty() && (char) postOpr.top.data != '(') {
                        postExpr += ((char) postOpr.top.data);
                        postOpr.pop();
                    }
                    postOpr.pop();
                }
            }
            if (paren != 0) {
                throw new Exception("Error");
            }
            while (!postOpr.isEmpty()) {
                postExpr += ((char) postOpr.top.data);
                postOpr.pop();
            }
        } catch (Exception e) {
            System.out.println("Error");
            System.exit(0);
        }
        return postExpr;
    }

    public int convert(Object operand) {
        int oper = 0;
        switch ((char) operand) {
            case 'a':
                oper = a;
                break;
            case 'b':
                oper = b;
                break;
            case 'c':
                oper = c;
                break;
            case 'd':
                oper = d;
                break;
        }
        return oper;
    }

    public int evaluate(String expression) {
        Stack postExpr = new Stack();
        int operand1, operand2, res;
        for (int i = 0; i < expression.length(); i++) {
            if (checkOpr(expression, i)) {
                postExpr.push(expression.charAt(i));
            } else {
                if (postExpr.size() == 1 && expression.charAt(i) == '-') {
                    if (checkChar(postExpr)) {
                        operand1 = -1 * eval.convert(postExpr.pop());
                    } else {
                        operand1 = -1 * (int) postExpr.pop();
                    }
                    postExpr.push(operand1);
                } else {
                    if (checkChar(postExpr)) {
                        operand2 = eval.convert(postExpr.pop());
                    } else {
                        operand2 = (int) postExpr.pop();
                    }
                    if (checkChar(postExpr)) {
                        operand1 = eval.convert(postExpr.pop());
                    } else {
                        operand1 = (int) postExpr.pop();
                    }
                    switch (expression.charAt(i)) {
                        case '+':
                            res = operand1 + operand2;
                            postExpr.push(res);
                            break;
                        case '-':
                            res = operand1 - operand2;
                            postExpr.push(res);
                            break;
                        case '*':
                            res = operand1 * operand2;
                            postExpr.push(res);
                            break;
                        case '/':
                            res = operand1 / operand2;
                            postExpr.push(res);
                            break;
                        case '^':
                            res = (int) Math.pow(operand1, operand2);
                            postExpr.push(res);
                            break;
                    }
                }
            }
        }
        if (checkChar(postExpr)) {
            postExpr.top.data = eval.convert(postExpr.peek());
        }
        return (int) postExpr.top.data;
    }
}