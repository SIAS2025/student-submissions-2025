public class preorderAndInorderTraversal {
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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTree1(preorder,0,preorder.length - 1,inorder,0,inorder.length - 1);
    }
     public TreeNode buildTree1(int[] preorder,int psStart,int psEnd,int[] inorder,int isStart,int isEnd) {
        if(psStart > psEnd) {
            return null;
        }
        if(psStart == psEnd) {
            return new TreeNode(preorder[psStart]);
        }
        TreeNode root = new TreeNode();
        root.val = preorder[psStart];
        int index = 0;
        for(int i = isStart;i <= isEnd;i++) {
            if(inorder[i] == root.val) {
                index = i;
            }
        }
        int leftSize = index - isStart;
        root.left = buildTree1(preorder,psStart + 1,psStart + leftSize,inorder,isStart,index - 1);
        root.right = buildTree1(preorder,psStart + leftSize + 1,psEnd,inorder,index + 1,isEnd);
        return root;
    }
}
