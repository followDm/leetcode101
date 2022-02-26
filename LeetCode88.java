import java.util.Scanner;

public class LeetCode88{
    public static void main(String[] args) {
        LeetCode88 solution = new LeetCode88();
        Scanner scanner = new Scanner(System.in);
        int[] numbers1, numbers2;
        int n = 0, m = 0;
        System.out.print("number of numbers1: ");
        m = scanner.nextInt();
        System.out.print("number of numbers2: ");
        n = scanner.nextInt();

        numbers1 = new int[m+n];
        for (int i = 1; i <= m; i++){
            numbers1[i-1] = scanner.nextInt();
        }
        numbers2 = new int[n];
        for (int i = 1; i <= n; i++){
            numbers2[i-1] = scanner.nextInt();
        }
        solution.merge(numbers1, m, numbers2, n);
        scanner.close();
    }

    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) {
                cur = nums2[p2--];
            } else if (p2 == -1) {
                cur = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            } else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
}
// number of numbers1: 3
// number of numbers2: 3
// 1 2 3
// 2 3 4