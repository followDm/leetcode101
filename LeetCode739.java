import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class LeetCode739 {
    public static void main(String[] args) {
        //一维整数数组
        LeetCode739 solution = new LeetCode739();
        Scanner scanner = new Scanner(System.in);
        
        int rows = 0;
        System.out.print("number of nums: ");
        rows = scanner.nextInt();
        int [] grid = new int[rows];
        for (int i = 1; i <= rows; i++){
            grid[i-1] = scanner.nextInt();
        }
        //单调栈
        solution.dailyTemperatures(grid);
        scanner.close();
    }
    public int[] dailyTemperatures(int[] temperatures) {
        int length = temperatures.length;
        int[] ans = new int[length];
        Deque<Integer> stack = new LinkedList<Integer>();
        for (int i = 0; i < length; i++) {
            int temperature = temperatures[i];
            while (!stack.isEmpty() && temperature > temperatures[stack.peek()]) {
                int prevIndex = stack.pop();
                ans[prevIndex] = i - prevIndex;
            }
            stack.push(i);
        }
        return ans;
    }
}

/*请根据每日 气温 列表 temperatures ，请计算在每一天需要等几天才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。*/
// 单调栈
// number of nums: 8
// 73 74 75 71 69 72 76 73
// [1,1,4,2,1,1,0,0]
// number of nums: 8
// 73 74 75 71 69 72 76 73
// [1,1,4,2,1,1,0,0]