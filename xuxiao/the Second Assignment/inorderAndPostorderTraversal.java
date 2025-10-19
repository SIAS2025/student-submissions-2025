public class inorderAndPostorderTraversal {
    public static class TreeNode {
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
 public static void main(String[] args) {
        buildTree(new int[]{2,1},new int[]{2,1});
 }
    public static TreeNode buildTree(int[] inorder, int[] postorder) {
        return buildTree1(inorder,0,inorder.length - 1,postorder,0,postorder.length - 1);
    }
    public static TreeNode buildTree1(int[] inorder,int isStart,int isEnd,int[] postorder,int psStart,int psEnd) {
        if(isStart > isEnd) {
            return null;
        }
        if(isStart == isEnd) {
            return new TreeNode(inorder[isStart]);
        }

        TreeNode root = new TreeNode();
        root.val = postorder[psEnd];
        int index = 0;
        for(int i = isStart;i <= isEnd;i++) {
            if(inorder[i] == root.val) {
                index = i;
            }
        }
        int leftSize = index - isStart;
        root.left = buildTree1(inorder,isStart,index - 1,postorder,psStart,psStart + leftSize - 1);
        root.right = buildTree1(inorder,index + 1,isEnd,postorder,psStart + leftSize,psEnd - 1);
        return root;
    }
}
