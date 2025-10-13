import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Preorder2 {
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
    public List<Integer> preorderTraversal(TreeNode root) {
        ArrayList<Integer> list = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
            if (root == null) {
                return list;
            }
            list.add(root.val);
            stack.push(root);
            while (root.left != null) {
                list.add(root.left.val);
                stack.push(root.left);
                root = root.left;
            }
            while (!stack.isEmpty()) {
                TreeNode node = stack.pop();
                root = node.right;
                if (root != null) {
                    list.add(root.val);
                    stack.push(root);
                    while (root.left != null) {
                        list.add(root.left.val);
                        stack.push(root.left);
                        root = root.left;
                    }
                }
            }
        return list;
    }
}
