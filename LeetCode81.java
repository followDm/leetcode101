import java.util.Scanner;

public class LeetCode81{
    public static void main(String[] args) {
        LeetCode81 solution = new LeetCode81();
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
        solution.search(numbers, n);
        scanner.close();
    }

    public boolean search(int[] nums, int target) {
        int n = nums.length;
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return nums[0] == target;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                ++l;
                --r;
            } else if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
}
// number of numbers: 7
// 2 5 6 0 0 1 2
// target: 2