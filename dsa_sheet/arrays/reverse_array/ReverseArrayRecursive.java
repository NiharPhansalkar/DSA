import java.util.Scanner;
// Iterative way
public class ReverseArrayRecursive {
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

        revArr(0, arr.length-1, arr);

        System.out.println("Reversed order is: ");

        for (int i : arr) {
            System.out.print(i + " ");
        }
    }

    static void revArr(int start, int end, int[] arr) {
        if (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            revArr(start+1, end-1, arr); 
        }
    }
}
