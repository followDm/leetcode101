import java.util.Scanner;

public class LeetCode34{
    public static void main(String[] args) {
        LeetCode34 solution = new LeetCode34();
        Scanner scanner = new Scanner(System.in);
        int[] numbers;
        int n = 0;
        System.out.print("number of numbers: ");
        n = scanner.nextInt();
        numbers = new int[n];
        for (int i = 1; i <= n; i++){
            numbers[i-1] = scanner.nextInt();
        }
        System.out.print("target: ");
        n = scanner.nextInt();
        solution.searchRange(numbers, n);
        scanner.close();
    }

    public int[] searchRange(int[] nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.length && nums[leftIdx] == target && nums[rightIdx] == target) {
            return new int[]{leftIdx, rightIdx};
        } 
        return new int[]{-1, -1};
    }

    public int binarySearch(int[] nums, int target, boolean lower) {
        int left = 0, right = nums.length - 1, ans = nums.length;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
}
// number of numbers: 6
// 5 7 7 8 8 10
// target: 8