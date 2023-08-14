import java.util.Arrays;
public class ZeroOneTwoSort {
    public static void main(String[] args) {
        int[] arr = {0, 2, 1, 2, 0};
        int j = 0;
        while (arr[j] == 0) {
            j++;
        }
        for (int i = j + 1; i < arr.length; i++) {
            if (arr[j] > arr[i]) {
                swap(arr, i, j);
                j++;
            }
        }

        System.out.println(Arrays.toString(arr));
    }

    static void swap(int[] arr, int start, int end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
}
