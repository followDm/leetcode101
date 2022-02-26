import java.util.Arrays;
import java.util.Scanner;

public class LeetCode455{
    public static void main(String[] args) {
        LeetCode455 solution = new LeetCode455();
        Scanner scanner = new Scanner(System.in);
        int[] children, cookies;
        int n = 0;
        System.out.print("number of children:");
        n = scanner.nextInt();
        children = new int[n];
        for (int i = 1; i <= n; i++){
            children[i-1] = scanner.nextInt();
        }
        System.out.print("number of cookies:");
        n = scanner.nextInt();
        cookies = new int[n];
        for (int i = 1; i <= n; i++){
            cookies[i-1] = scanner.nextInt();
        }
        System.out.println(solution.findContentChildren(children, cookies));
        scanner.close();
    }

    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int numOfChildren = g.length, numOfCookies = s.length;
        int count = 0;
        for (int i = 0, j = 0; i < numOfChildren && j < numOfCookies; i++, j++) {
            while (j < numOfCookies && g[i] > s[j]) {
                j++;
            }
            if (j < numOfCookies) {
                count++;
            }
        }
        return count;
    }
}