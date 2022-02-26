import java.util.Scanner;

public class LeetCode167{
    public static void main(String[] args) {
        LeetCode167 solution = new LeetCode167();
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
        solution.twoSum(numbers, n);
        scanner.close();
    }

    public int[] twoSum(int[] numbers, int target) {
        int low = 0, high = numbers.length - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return new int[]{low + 1, high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        return new int[]{-1, -1};
    }
}
// number of numbers:4
// 2 7 11 13
// target:9