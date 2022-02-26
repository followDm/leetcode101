import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class LeetCode104 {
    
    public static void main(String[] args) {
        //两个一维整数数组
        LeetCode104 solution = new LeetCode104();
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
        TreeNode tn = solution.buildTree(numbers1, numbers2);
        //递归求解最大深度
        solution.maxDepth(tn);
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
    int maxDepth(TreeNode root){
        return root==null ? 1 + Math.max(maxDepth(root.left),maxDepth(root.right)) : 0;
    }
}

/*给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。*/
// number of nums1: 5
// 3 9 20 15 7
// number of nums1: 5
// 9 3 15 20 7
// 3
// number of num1: 5
// 3 9 20 15 7
// number of num2: 5
// 9 3 15 20 7