import java.util.Arrays;
public class ZeroOneTwoBetter {
    public static void main(String[] args) {
        int[] arr = {0,2,1,2,0,1,1,0,0,0,2,2,1,2,0};
        int countZero = 0, countOne = 0, countTwo = 0;
        for (int i : arr) {
            if (i == 0) {
                countZero += 1; 
            } else if (i == 1) {
                countOne += 1; 
            } else {
                countTwo += 1;
            }
        }
        int j = 0;
        while (countZero-- != 0) {
            arr[j++] = 0;
        }
        while (countOne-- != 0) {
            arr[j++] = 1;
        }
        while (countTwo-- != 0) {
            arr[j++] = 2;
        }

        System.out.println(Arrays.toString(arr));
    }
}
