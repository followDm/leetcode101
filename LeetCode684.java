import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class LeetCode684 {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] parent = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            int[] edge = edges[i];
            int node1 = edge[0], node2 = edge[1];
            if (find(parent, node1) != find(parent, node2)) {
                union(parent, node1, node2);
            } else {
                return edge;
            }
        }
        return new int[0];
    }

    public void union(int[] parent, int index1, int index2) {
        parent[find(parent, index1)] = find(parent, index2);
    }

    public int find(int[] parent, int index) {
        if (parent[index] != index) {
            parent[index] = find(parent, parent[index]);
        }
        return parent[index];
    }
    public static void main(String[] args) {
        //二维整数数组
        LeetCode684 solution = new LeetCode684();
        Scanner scanner = new Scanner(System.in);
        int [][] grid;
        int rows = 0, columns = 2;
        System.out.print("number of edges: ");
        rows = scanner.nextInt();
        grid = new int[rows][columns];
        for (int i = 1; i <= rows; i++){
            for (int j = 1; j <= 2; j++){
                grid[i-1][j-1] = scanner.nextInt();
            }
        }
        //并查集
        solution.findRedundantConnection(grid);
        scanner.close();
    }
}
/*树可以看成是一个连通且 无环 的 无向 图。

给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。

请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的边。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/redundant-connection
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of edges: 3
// 1 2
// 2 3
// 1 3
// [1,3]
// number of edges: 3
// 1 2
// 2 3
// 1 3
// [1,3]