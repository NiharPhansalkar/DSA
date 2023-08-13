import java.util.Scanner;

public class MaxAndMinInArray {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the size of your array");
        int size = in.nextInt(); 
        int[] arr = new int[size];

        System.out.println("Enter values into the array");

        for (int i = 0; i < arr.length; i++) {
            System.out.print("Value " + (i + 1) + " ");
            arr[i] = in.nextInt();
            System.out.println();
        }

        int[] val = maxAndMin(arr);

        for (int i : val) {
            System.out.println(i);
        }
    }

    static int[] maxAndMin(int[] arr) {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;

        for (int i : arr) {
            if (i > max) {
                max = i;
            }
            if (i < min) {
                min = i;
            }
        }

        int[] retMe = new int[2];
        retMe[0] = min;
        retMe[1] = max;
        return retMe;
    }
}