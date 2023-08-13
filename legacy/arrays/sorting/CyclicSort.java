import java.util.Arrays;
import java.util.Scanner;

public class CyclicSort {
    public static void main(String[] args) {
        System.out.println("How many values would you like?");
        Scanner in = new Scanner(System.in);
        int values = in.nextInt();
        int[] arr = new int[values];

        for (int i = 0; i < values; i++) {
            System.out.print("> ");
            arr[i] = in.nextInt();    
        }

        cyclicSort(arr);
        
        System.out.println(Arrays.toString(arr));
        
        in.close();
    }

    static void cyclicSort(int[] arr) {
        int i = 0;
        while (i < arr.length) {
            int correct = arr[i] - 1;
            if (arr[i] != arr[correct]) {
                swap(arr, i, correct);
                continue;
            }
            i++;
        }
    }

    static void swap(int[] arr, int indexOne, int indexSecond) {
        int temp = arr[indexOne];
        arr[indexOne] = arr[indexSecond];
        arr[indexSecond] = temp;
    }
}
