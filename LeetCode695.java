import java.util.Scanner;
import java.util.Deque;
import java.util.LinkedList;

public class LeetCode695{
    public static void main(String[] args) {
        LeetCode695 solution = new LeetCode695();
        Scanner scanner = new Scanner(System.in);
        int [][] grid;
        int rows = 0, columns = 0;
        System.out.print("number of rows: ");
        rows = scanner.nextInt();
        System.out.print("number of columns:");
        columns = scanner.nextInt();
        grid = new int[rows][columns];
        for (int i = 1; i <= rows; i++){
            for (int j = 1; j <= columns; j++){
                grid[i-1][j-1] = scanner.nextInt();
            }
        }
        System.out.println(solution.maxAreaOfIsland(grid));
        scanner.close();
    }

    public int maxAreaOfIsland(int[][] grid) {
        int ans = 0;
        for (int i = 0; i != grid.length; ++i) {
            for (int j = 0; j != grid[0].length; ++j) {
                int cur = 0;
                Deque<Integer> stacki = new LinkedList<Integer>();
                Deque<Integer> stackj = new LinkedList<Integer>();
                stacki.push(i);
                stackj.push(j);
                while (!stacki.isEmpty()) {
                    int cur_i = stacki.pop(), cur_j = stackj.pop();
                    
                    //重点是!=1
                    if (cur_i < 0 || cur_j < 0 || cur_i == grid.length || cur_j == grid[0].length || grid[cur_i][cur_j] != 1) {
                        continue;
                    }
                    ++cur;
                    grid[cur_i][cur_j] = 0;
                    int[] di = {0, 0, 1, -1};
                    int[] dj = {1, -1, 0, 0};
                    // 添加方向后的位置坐标
                    for (int index = 0; index != 4; ++index) {
                        int next_i = cur_i + di[index], next_j = cur_j + dj[index];
                        stacki.push(next_i);
                        stackj.push(next_j);
                    }
                }
                ans = Math.max(ans, cur);
            }
        }
        return ans;
    }
}
// number of rows: 3
// number of columns: 8
// 1 0 1 1 0 1 0 1
// 1 0 1 1 0 1 1 1
// 0 0 0 0 0 0 0 1
// 6