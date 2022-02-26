import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class LeetCode204 {
    public static void main(String[] args) {
        //一个整数
        LeetCode204 solution = new LeetCode204();
        Scanner scanner = new Scanner(System.in);

        System.out.print("prime: ");
        int n = scanner.nextInt();
        //筛选素数
        solution.countPrimes(n); 
        scanner.close();
    }
    public int countPrimes(int n) {
        List<Integer> primes = new ArrayList<Integer>();
        int[] isPrime = new int[n];
        Arrays.fill(isPrime, 1);
        for (int i = 2; i < n; ++i) {
            if (isPrime[i] == 1) {
                primes.add(i);
            }
            for (int j = 0; j < primes.size() && i * primes.get(j) < n; ++j) {
                isPrime[i * primes.get(j)] = 0;
                if (i % primes.get(j) == 0) {
                    break;
                }
            }
        }
        return primes.size();
    }
}
/*统计所有小于非负整数 n 的质数的数量。*/
// 埃式筛法
// n: 7
// 3