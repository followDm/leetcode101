import java.util.Scanner;
import java.util.List;
import java.util.Collections;
import java.util.ArrayList;

public class LeetCode46{
    public static void main(String[] args) {
        LeetCode46 solution = new LeetCode46();
        Scanner scanner = new Scanner(System.in);
        int [] grid;
        int rows = 0, columns = 0;
        System.out.print("number of nums: ");
        rows = scanner.nextInt();
        grid = new int[rows];
        for (int i = 1; i <= rows; i++){
            grid[i-1] = scanner.nextInt();
        }
        solution.permute(grid);
        scanner.close();
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();

        List<Integer> output = new ArrayList<Integer>();
        for (int num : nums) {
            output.add(num);
        }

        int n = nums.length;
        backtrack(n, output, res, 0);
        return res;
    }

    public void backtrack(int n, List<Integer> output, List<List<Integer>> res, int first) {
        // 所有数都填完了
        if (first == n) {
            res.add(new ArrayList<Integer>(output));
        }
        for (int i = first; i < n; i++) {
            // 动态维护数组
            Collections.swap(output, first, i);
            // 继续递归填下一个数
            backtrack(n, output, res, first + 1);
            // 撤销操作
            Collections.swap(output, first, i);
        }
    }
}

// number of nums: 3
// 1 2 3
// [[1,2,3][1,3,2][2,1,3][2,3,1][3,2,1][3,1,2]]