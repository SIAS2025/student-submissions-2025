/*
    Construct Binary Tree from Inorder and Postorder Traversal
*/

class Solution {
TreeNode* cteateTree(vector<int>& inorder, int s1, int e1, vector<int>& postorder, int s2, int e2)
{
    if(e1 < s1)
        return nullptr;

    int len = e1 - s1 + 1;
    int root_val = postorder[e2];
    TreeNode* root = new TreeNode(root_val);
    int root_index = 0;
    for(int i = s1; i <= e1; i++)
    {
        if(root_val == inorder[i])
        {
            root_index = i;
            break;
        }     
    }
    
    int left_len = root_index - s1;
    root->left = cteateTree(inorder, s1, s1 + left_len - 1, postorder, s2, s2 + left_len - 1);
    root->right = cteateTree(inorder, s1 + left_len + 1, e1, postorder, s2 + left_len, e2 - 1);
    
    return root;
}
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int end = inorder.size() - 1;
        return cteateTree(inorder, 0, end, postorder, 0, end);
    }
};