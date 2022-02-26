import java.util.Scanner;

public class LeetCode135{
    public static void main(String[] args) {
        LeetCode135 solution = new LeetCode135();
        Scanner scanner = new Scanner(System.in);
        int[] ratings;
        int n = 0;
        System.out.print("number of children:");
        n = scanner.nextInt();
        ratings = new int[n];
        for (int i = 1; i <= n; i++){
            ratings[i-1] = scanner.nextInt();
        }
        System.out.println(solution.candy(ratings));
        scanner.close();
    }

    public int candy(int[] ratings) {
        int n = ratings.length;
        int ret = 1;
        int inc = 1, dec = 0, pre = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ret += pre;
                inc = pre;
            } else {
                dec++;
                if (dec == inc) {
                    dec++;
                }
                ret += dec;
                pre = 1;
            }
        }
        return ret;
    }
}