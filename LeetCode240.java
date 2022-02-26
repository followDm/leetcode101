import java.util.Scanner;

public class LeetCode240 {
    public static void main(String[] args) {
        //二维整数数组
        LeetCode240 solution = new LeetCode240();
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
        System.out.print("target:");
        int target = scanner.nextInt();
        //利用行列的大小性质，主要是从最后一行开始
        solution.searchMatrix(grid, target);
        scanner.close();
    }
    public boolean searchMatrix(int[][] matrix, int target) {
        // start our "pointer" in the bottom-left
        int row = matrix.length-1;
        int col = 0;

        while (row >= 0 && col < matrix[0].length) {
            if (matrix[row][col] > target) {
                row--;
            } else if (matrix[row][col] < target) {
                col++;
            } else { // found it
                return true;
            }
        }

        return false;
    }
}

/*编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of rows: 2
// number of columns: 5
// 1 4 7 11 15
// 2 5 7 12 19
// target: 5
// true