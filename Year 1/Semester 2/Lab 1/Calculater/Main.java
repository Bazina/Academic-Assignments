import java.util.*;

interface ICalculator {
    int add(int x, int y);
    float divide(int x, int y) throws RuntimeException;
}

class Calculator implements ICalculator{
    public int add (int x, int y){
        System.out.println(x + y);
        return 0;
    }
    public float divide (int x, int y){
        if (y == 0) {
            throw new RuntimeException("Error");
        } else {
            System.out.println((float) x / y);
            return 0;
        }
    }

}

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int x = input.nextInt();
        char operator = input.next().charAt(0);
        int y = input.nextInt();
        Calculator calc = new Calculator();
        if (operator == '+') {
            calc.add(x, y);
        } else if (operator == '/') {
            try {
                calc.divide(x, y);
            }
            catch (RuntimeException e) {
                System.out.println("Error");
            }
        }
        input.close();
    }
}
