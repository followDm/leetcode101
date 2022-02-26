import java.util.Scanner;

public class LeetCode69{
    public static void main(String[] args) {
        LeetCode69 solution = new LeetCode69();
        Scanner scanner = new Scanner(System.in);
        int n = 0;
        System.out.print("target: ");
        n = scanner.nextInt();
        System.out.println(solution.mySqrt(n));
        scanner.close();
    }

    public int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long) mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
}
// target: 9
// 3