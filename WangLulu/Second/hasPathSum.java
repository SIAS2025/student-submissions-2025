package Second;

public class hasPathSum {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root==null){
            return false;
        }
        targetSum = targetSum-root.val;
        if(root.left==null && root.right==null){
            return targetSum == 0;
        }
        if(root.left!=null){
            boolean left =hasPathSum(root.left,targetSum);
            if(left){
                return true;
            }
        }
        if(root.right!=null){
            boolean right = hasPathSum(root.right,targetSum);
            if(right){
                return true;
            }
        }
        return false;


    }
}
