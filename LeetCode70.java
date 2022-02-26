import java.util.Scanner;

class LeetCode70 {
    public static void main(String[] args) {
        LeetCode70 solution = new LeetCode70();
        Scanner scanner = new Scanner(System.in);

        System.out.print("size of stairs: ");
        int n = scanner.nextInt();
        
        solution.climbStairs(n); 
        scanner.close();
    }
    //动态规划
    public int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
    }
    //线性代数方法之矩阵
    // public int climbStairs(int n) {
    //     int[][] q = {{1, 1}, {1, 0}};
    //     int[][] res = pow(q, n);
    //     return res[0][0];
    // }

    public int[][] pow(int[][] a, int n) {
        int[][] ret = {{1, 0}, {0, 1}};
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return ret;
    }

    public int[][] multiply(int[][] a, int[][] b) {
        int[][] c = new int[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }
}
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。*/
// 官方有矩阵幂的计算方式
// 最后试了试n=100等的数字，当n比较大的时候，中间的部分数字由于超出了整数或者长整数的表示范围，出现负数不可避免
// 一维动态规划
// n: 3
// 3