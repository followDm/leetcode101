import java.util.Scanner;
import java.util.Queue;
import java.util.Stack;
import java.util.Set;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.HashSet;

public class LeetCode934{
    public static void main(String[] args) {
        LeetCode934 solution = new LeetCode934();
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
        System.out.println(solution.shortestBridge(grid)); 
        scanner.close();
    }

    public int shortestBridge(int[][] A) {
        int R = A.length, C = A[0].length;
        int[][] colors = getComponents(A);

        Queue<Node> queue = new LinkedList();
        Set<Integer> target = new HashSet();
        //1是指第一块岛屿，2指第二块岛屿
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c) {
                if (colors[r][c] == 1) {
                    queue.add(new Node(r, c, 0));
                } else if (colors[r][c] == 2) {
                    target.add(r * C + c);
                }
            }

        while (!queue.isEmpty()) {
            Node node = queue.poll();
            if (target.contains(node.r * C + node.c))
                return node.depth - 1;
            for (int nei: neighbors(A, node.r, node.c)) {
                int nr = nei / C, nc = nei % C;
                if (colors[nr][nc] != 1) {
                    queue.add(new Node(nr, nc, node.depth + 1));
                    colors[nr][nc] = 1;
                }
            }
        }

        throw null;
    }

    public int[][] getComponents(int[][] A) {
        int R = A.length, C = A[0].length;
        int[][] colors = new int[R][C];
        int t = 0;

        for (int r0 = 0; r0 < R; ++r0)
            for (int c0 = 0; c0 < C; ++c0)
                if (colors[r0][c0] == 0 && A[r0][c0] == 1) {
                    // Start dfs 目的是找到两块岛屿
                    Stack<Integer> stack = new Stack();
                    stack.push(r0 * C + c0);
                    colors[r0][c0] = ++t;

                    while (!stack.isEmpty()) {
                        int node = stack.pop();
                        int r = node / C, c = node % C;
                        for (int nei: neighbors(A, r, c)) {
                            int nr = nei / C, nc = nei % C;
                            if (A[nr][nc] == 1 && colors[nr][nc] == 0) {
                                colors[nr][nc] = t;
                                stack.push(nr * C + nc);
                            }
                        }
                    }
                }

        return colors;
    }

    public List<Integer> neighbors(int[][] A, int r, int c) {
        int R = A.length, C = A[0].length;
        List<Integer> ans = new ArrayList();
        if (0 <= r-1) ans.add((r-1) * R + c);
        if (0 <= c-1) ans.add(r * R + (c-1));
        if (r+1 < R) ans.add((r+1) * R + c);
        if (c+1 < C) ans.add(r * R + (c+1));
        return ans;
    }
}

class Node {
    int r, c, depth;
    Node(int r, int c, int d) {
        this.r = r;
        this.c = c;
        depth = d;
    }
}

// number of rows: 3
// number of columns: 3
// 0 0 1
// 0 0 0
// 1 0 0
// 3