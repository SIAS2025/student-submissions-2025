import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Postorder2 {
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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode prev = null;
        while (root != null || !stack.isEmpty()) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            TreeNode node = stack.peek();
            if (node.right == null || node.right == prev) {
                list.add(node.val);
                stack.pop();
                prev = node;
                root = null;
            } else {
                root = node.right;
            }
        }
        return list;
    }

}
