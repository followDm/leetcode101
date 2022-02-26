import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class LeetCode210 {
    public static void main(String[] args) {
        //二维整数数组
        LeetCode210 solution = new LeetCode210();
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
        System.out.println("number of courses: ");
        int target = scanner.nextInt();
        //拓扑排序，广度优先
        solution.findOrder(target, grid);
        scanner.close();
    }
    // 存储有向图
    List<List<Integer>> edges;
    // 存储每个节点的入度
    int[] indeg;
    // 存储答案
    int[] result;
    // 答案下标
    int index;

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        edges = new ArrayList<List<Integer>>();
        for (int i = 0; i < numCourses; ++i) {
            edges.add(new ArrayList<Integer>());
        }
        indeg = new int[numCourses];
        result = new int[numCourses];
        index = 0;
        for (int[] info : prerequisites) {
            edges.get(info[1]).add(info[0]);
            ++indeg[info[0]];
        }

        Queue<Integer> queue = new LinkedList<Integer>();
        // 将所有入度为 0 的节点放入队列中
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                queue.offer(i);
            }
        }

        while (!queue.isEmpty()) {
            // 从队首取出一个节点
            int u = queue.poll();
            // 放入答案中
            result[index++] = u;
            for (int v: edges.get(u)) {
                --indeg[v];
                // 如果相邻节点 v 的入度为 0，就可以选 v 对应的课程了
                if (indeg[v] == 0) {
                    queue.offer(v);
                }
            }
        }

        if (index != numCourses) {
            return new int[0];
        }
        return result;
    }
}

/*现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。

例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of edges: 4
// 1 0
// 2 0
// 3 1
// 3 2
// number of courses: 4
// [0,1,2,3]
// number of edges: 4
// 1 0
// 2 0
// 3 1
// 3 2
// number of courses: 4
// [0,1,2,3]