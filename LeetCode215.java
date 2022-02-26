import java.util.Scanner;
import java.util.Random;

public class LeetCode215{
    public static void main(String[] args) {
        LeetCode215 solution = new LeetCode215();
        Scanner scanner = new Scanner(System.in);
        int[] numbers;
        int n = 0;
        System.out.print("number of numbers: ");
        n = scanner.nextInt();
        numbers = new int[n];
        for (int i = 1; i <= n; i++){
            numbers[i-1] = scanner.nextInt();
        }
        System.out.print("target: ");
        n = scanner.nextInt();
        solution.findKthLargest(numbers, n);
        scanner.close();
    }

    public int findKthLargest(int[] nums, int k) {
        int heapSize = nums.length;
        buildMaxHeap(nums, heapSize);
        for (int i = nums.length - 1; i >= nums.length - k + 1; --i) {
            swap(nums, 0, i);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }

    public void buildMaxHeap(int[] a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        } 
    }

    public void maxHeapify(int[] a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        } 
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a, i, largest);
            maxHeapify(a, largest, heapSize);
        }
    }

    // 以下是快速选择排序
    Random random = new Random();

    // public int findKthLargest(int[] nums, int k) {
    //     return quickSelect(nums, 0, nums.length - 1, nums.length - k);
    // }

    public int quickSelect(int[] a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    public int randomPartition(int[] a, int l, int r) {
        int i = random.nextInt(r - l + 1) + l;
        swap(a, i, r);
        return partition(a, l, r);
    }

    public int partition(int[] a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a, ++i, j);
            }
        }
        swap(a, i + 1, r);
        return i + 1;
    }

    public void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
// number of numbers: 6
// 5 4 1 2 6 3
// target: 2