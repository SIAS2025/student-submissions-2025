import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Inorder2 {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> list = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        if (root == null) {
            return list;
        }
        stack.push(root);
        while (root.left != null) {
            stack.push(root.left);
            root = root.left;
        }
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            list.add(node.val);
            root = node.right;
            if (root != null) {
                stack.push(root);
                while (root.left != null) {
                    stack.push(root.left);
                    root = root.left;
                }
            }
        }
        return list;
    }
}
