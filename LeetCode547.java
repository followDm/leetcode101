import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class LeetCode547{
    public static void main(String[] args) {
        LeetCode547 solution = new LeetCode547();
        Scanner scanner = new Scanner(System.in);
        int [][] grid;
        int rows = 0, columns = 0;
        System.out.print("number of friends: ");
        rows = scanner.nextInt();
        grid = new int[rows][rows];
        for (int i = 1; i <= rows; i++){
            for (int j = 1; j <= rows; j++){
                grid[i-1][j-1] = scanner.nextInt();
            }
        }
        System.out.println(solution.findCircleNum(grid));
        scanner.close();
    }

    public int findCircleNum(int[][] isConnected) {
        int provinces = isConnected.length;
        boolean[] visited = new boolean[provinces];
        int circles = 0;
        Queue<Integer> queue = new LinkedList<Integer>();
        for (int i = 0; i < provinces; i++) {
            if (!visited[i]) {
                queue.offer(i);
                while (!queue.isEmpty()) {
                    int j = queue.poll();
                    visited[j] = true;
                    for (int k = 0; k < provinces; k++) {
                        if (isConnected[j][k] == 1 && !visited[k]) {
                            queue.offer(k);
                        }
                    }
                }
                circles++;
            }
        }
        return circles;
    }
}
// number of friends: 3
// 1 1 0
// 1 1 0
// 0 0 1
// 2