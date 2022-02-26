import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class LeetCode1110 {
    
    public static void main(String[] args) {
        //两个一维整数数组
        LeetCode1110 solution = new LeetCode1110();
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
        //删除树的结点
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

/*给出二叉树的根节点 root，树上每个节点都有一个不同的值。

如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。

返回森林中的每棵树。你可以按任意顺序组织答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-nodes-and-return-forest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of num1: 7
// 1 2 4 5 3 6 7
// number of num2: 7
// 4 2 5 1 6 3 7
// number of dels: 2
// 3 5