import java.util.Scanner;

public class LeetCode79{
    public static void main(String[] args) {
        LeetCode79 solution = new LeetCode79();
        Scanner scanner = new Scanner(System.in);
        char [][] board;
        int rows = 0, columns = 0;
        System.out.print("number of rows: ");
        rows = scanner.nextInt();
        System.out.print("number of columns:");
        columns = scanner.nextInt();
        board = new char[rows][columns];
        for (int i = 1; i <= rows; i++){
            for (int j = 1; j <= columns; j++){
                board[i-1][j-1] = scanner.next().charAt(0);
            }
        }
        System.out.println("word: ");
        String word = scanner.nextLine();
        solution.exist(board, word);
        scanner.close();
    }
    public boolean exist(char[][] board, String word) {
        int h = board.length, w = board[0].length;
        boolean[][] visited = new boolean[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                boolean flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean check(char[][] board, boolean[][] visited, int i, int j, String s, int k) {
        if (board[i][j] != s.charAt(k)) {
            return false;
        } else if (k == s.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        boolean result = false;
        for (int[] dir : directions) {
            int newi = i + dir[0], newj = j + dir[1];
            if (newi >= 0 && newi < board.length && newj >= 0 && newj < board[0].length) {
                if (!visited[newi][newj]) {
                    boolean flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }
}
// number of rows: 3
// number of columns: 4
// a b c e
// s f c s
// a d e e
// s: abcced
// true