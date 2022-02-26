import java.util.Scanner;

public class LeetCode48 {
    public static void main(String[] args) {
        //二维整数数组
        LeetCode48 solution = new LeetCode48();
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
        //数组顺时针旋转90°；与C++版本代码不同
        solution.rotate(grid);
        scanner.close();
    }
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        // 水平翻转
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = temp;
            }
        }
        // 主对角线翻转
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
}

/*给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-image
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of rows: 3
// 1 2 3 
// 4 5 6
// 7 8 9
// [[7,4,1][8,5,2][9,6,3]]
// number of rows: 3
// 1 2 3 
// 4 5 6
// 7 8 9
// [[7,4,1][8,5,2][9,6,3]]