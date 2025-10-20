/*
    Maximum Depth of Binary Tree
*/

//solution 1: up-down
class Solution {
void up_down_Depth(TreeNode* root, int depth_now)
{
    if(!root)
        return;
    if(!root->left && !root->right)
        Depth = max(Depth, depth_now + 1);
    
    up_down_Depth(root->right, depth_now + 1);
    up_down_Depth(root->left, depth_now + 1);
}
public:
    int maxDepth(TreeNode* root) {
        Depth = 0;
        up_down_Depth(root, Depth);
        return Depth;
    }

    int Depth;
};

//solution 2: bottom-up
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};