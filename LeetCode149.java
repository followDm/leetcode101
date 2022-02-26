import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class LeetCode149 {
    public static void main(String[] args) {
        //二维整数数组
        LeetCode149 solution = new LeetCode149();
        Scanner scanner = new Scanner(System.in);
        int [][] grid;
        int rows = 0, columns = 0;
        System.out.print("number of points: ");
        rows = scanner.nextInt();
        grid = new int[rows][2];
        for (int i = 1; i <= rows; i++){
            for (int j = 1; j <= 2; j++){
                grid[i-1][j-1] = scanner.nextInt();
            }
        }
        //哈希表；直线上最多的点
        solution.maxPoints(grid);
        scanner.close();
    }
    public int maxPoints(int[][] points) {
        int n = points.length;
        if (n <= 2) {
            return n;
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (ret >= n - i || ret > n / 2) {
                break;
            }
            Map<Integer, Integer> map = new HashMap<Integer, Integer>();
            for (int j = i + 1; j < n; j++) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if (x == 0) {
                    y = 1;
                } else if (y == 0) {
                    x = 1;
                } else {
                    if (y < 0) {
                        x = -x;
                        y = -y;
                    }
                    int gcdXY = gcd(Math.abs(x), Math.abs(y));
                    x /= gcdXY;
                    y /= gcdXY;
                }
                int key = y + x * 20001;
                map.put(key, map.getOrDefault(key, 0) + 1);
            }
            int maxn = 0;
            for (Map.Entry<Integer, Integer> entry: map.entrySet()) {
                int num = entry.getValue();
                maxn = Math.max(maxn, num + 1);
            }
            ret = Math.max(ret, maxn);
        }
        return ret;
    }

    public int gcd(int a, int b) {
        return b != 0 ? gcd(b, a % b) : a;
    }
}

/*给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。*/
// 哈希表又是个困难题
// number of points: 3
// 1 1
// 2 2
// 3 0
// 2
// number of points: 3
// 1 1
// 2 2
// 3 0
// 2