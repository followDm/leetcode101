import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

public class LeetCode435{
    public static void main(String[] args) {
        LeetCode135 solution = new LeetCode135();
        Scanner scanner = new Scanner(System.in);
        int[] ratings;
        int n = 0;
        System.out.print("number of children:");
        n = scanner.nextInt();
        ratings = new int[n];
        for (int i = 1; i <= n; i++){
            ratings[i-1] = scanner.nextInt();
        }
        System.out.println(solution.candy(ratings));
        scanner.close();
    }

    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) {
            return 0;
        }
        
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] interval1, int[] interval2) {
                return interval1[1] - interval2[1];
            }
        });

        int n = intervals.length;
        int right = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= right) {
                ++ans;
                right = intervals[i][1];
            }
        }
        return n - ans;
    }
}