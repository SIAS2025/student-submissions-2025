class Solution {
bool check_Symmetric(TreeNode* l_node, TreeNode* r_node)
{
    if(!l_node && !r_node)
        return true;
    if((l_node && !r_node) || (!l_node && r_node))
        return false;
    if(l_node->val != r_node->val)
        return false;
    
    return check_Symmetric(l_node->left, r_node->right) && check_Symmetric(l_node->right, r_node->left);
}
public:
    bool isSymmetric(TreeNode* root) {
        //up-down
        if(!root)
            return true;
        return check_Symmetric(root->left, root->right);
    }
};