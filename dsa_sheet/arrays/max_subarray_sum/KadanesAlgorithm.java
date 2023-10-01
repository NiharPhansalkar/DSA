// This is the code for Kadane's Algorithm
public class KadanesAlgorithm {
    public static void main(String[] args) {
        int[] nums = [-2, 1, -3, 4, -1, 2, 1, -5 ,4];
        int maxSubarrSum = kadane(nums);

        System.out.println("The maximum subarray sum is " + maxSubarrSum);
    }

    public static int kadane(int[] arr) {
        int sum = 0, maximum = arr[0];

        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            maximum = Math.max(sum, maximum);
            if (sum < 0) {
                sum = 0;
            }
        }

        return maximum;
    }
}
