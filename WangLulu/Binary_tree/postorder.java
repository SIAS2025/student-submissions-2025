package Binary_tree;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;


public class postorder {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        lrd(root, result);
        return result;
    }

    public void lrd(TreeNode root, List<Integer> result) {
        if (root == null) {
            return;
        }
        lrd(root.left, result);
        lrd(root.right, result);
        result.add(root.val);

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
class postorder2{
    public class TreeNode {
        int val;
        postorder2.TreeNode left;
        postorder2.TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, postorder2.TreeNode left, postorder2.TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    public List<Integer> postorderTraversal(postorder2.TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        if(root==null){
            return result;
        }
        stack.push(root);
        result.add(root.val);
        while(!stack.isEmpty()){
            TreeNode node = stack.pop();
            if(node.left!=null){
                stack.push(node);
            }
            if(node.right!=null){
                stack.push(node);
            }
        }
        Collections.reverse(result);
        return result;

    }

}

