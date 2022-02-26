import java.util.Scanner;

public class LeetCode417{
    public static void main(String[] args) {
        LeetCode417 solution = new LeetCode417();
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
        scanner.close();
    }
}
// number of rows: 3
// number of columns: 8
// 1 0 1 1 0 1 0 1
// 1 0 1 1 0 1 1 1
// 0 0 0 0 0 0 0 1
// 6