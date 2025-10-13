package Binary_tree;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class inorder {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        ldr(root, result);
        return result;
    }

    public void ldr(TreeNode root, List<Integer> result) {
        if (root == null) {
            return;
        }

        ldr(root.left, result);
        result.add(root.val);
        ldr(root.right, result);

    }
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}
//迭代
class inorder2 {
    public class TreeNode {
        int val;
        inorder2.TreeNode left;
        inorder2.TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, inorder2.TreeNode left, inorder2.TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public List<Integer> inorderTraversal(inorder2.TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<inorder2.TreeNode> stack = new Stack<>();
        if (root == null) {
            return result;
        }
        inorder2.TreeNode cur = root;
        while (cur != null || !stack.isEmpty()) {
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }
            cur = stack.pop();
            result.add(cur.val);

            cur = cur.right;

        }
        return result;
    }
}


















