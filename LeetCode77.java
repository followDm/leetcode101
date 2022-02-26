import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class LeetCode77{
    public static void main(String[] args) {
        LeetCode77 solution = new LeetCode77();
        Scanner scanner = new Scanner(System.in);
        
        int n = 0, t = 0;
        System.out.print("number of n: ");
        n = scanner.nextInt();
        System.out.print("number of t(t<=n): ");
        t = scanner.nextInt();
        solution.combine(n, t);
        scanner.close();
    }
    List<Integer> temp = new ArrayList<Integer>();
    List<List<Integer>> ans = new ArrayList<List<Integer>>();

    public List<List<Integer>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }

    public void dfs(int cur, int n, int k) {
        // 剪枝：temp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 temp
        if (temp.size() + (n - cur + 1) < k) {
            return;
        }
        // 记录合法的答案
        if (temp.size() == k) {
            ans.add(new ArrayList<Integer>(temp));
            return;
        }
        // 考虑选择当前位置
        temp.add(cur);
        dfs(cur + 1, n, k);
        temp.remove(temp.size() - 1);
        // 考虑不选择当前位置
        dfs(cur + 1, n, k);
    }
}
// number of n: 4
// number of t(t<=n): 2
// [[1,2][1,3][1,4][2,3][2,4][3,4]]