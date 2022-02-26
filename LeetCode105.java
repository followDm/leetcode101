import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class LeetCode105 {
    
    public static void main(String[] args) {
        //两个一维整数数组
        LeetCode105 solution = new LeetCode105();
        Scanner scanner = new Scanner(System.in);
        int[] numbers1, numbers2;
        int n = 0, m = 0;
        System.out.print("number of num1: ");
        m = scanner.nextInt();
        System.out.print("number of num2: ");
        n = scanner.nextInt();

        numbers1 = new int[m+n];
        for (int i = 1; i <= m; i++){
            numbers1[i-1] = scanner.nextInt();
        }
        numbers2 = new int[n];
        for (int i = 1; i <= n; i++){
            numbers2[i-1] = scanner.nextInt();
        }
        //先序中序
        solution.buildTree(numbers1, numbers2);
        scanner.close();
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || preorder.length == 0) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[0]);
        Deque<TreeNode> stack = new LinkedList<TreeNode>();
        stack.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.length; i++) {
            int preorderVal = preorder[i];
            TreeNode node = stack.peek();
            if (node.val != inorder[inorderIndex]) {
                node.left = new TreeNode(preorderVal);
                stack.push(node.left);
            } else {
                while (!stack.isEmpty() && stack.peek().val == inorder[inorderIndex]) {
                    node = stack.pop();
                    inorderIndex++;
                }
                node.right = new TreeNode(preorderVal);
                stack.push(node.right);
            }
        }
        return root;
    }
}
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { 
        this.val = val; 
    }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
/*
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/cong-qian-xu-yu-zhong-xu-bian-li-xu-lie-gou-zao-9/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
// number of num1: 5
// 3 9 20 15 7
// number of num2: 5
// 9 3 15 20 7