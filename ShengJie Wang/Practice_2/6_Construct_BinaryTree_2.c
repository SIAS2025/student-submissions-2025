/*
    Construct Binary Tree from Preorder and Inorder Traversal
*/

class Solution {
TreeNode* createTree(vector<int>& preorder, int s1, int e1, vector<int>& inorder, int s2, int e2)
{
    if(e1 <s1)
        return nullptr;
    int root_val = preorder[s1];
    TreeNode* root = new TreeNode(root_val);
    int root_index = 0;
    for(int i = s2; i <= e2; i++)
    {
        if(inorder[i] == root_val)
        {
            root_index = i;
            break;
        }
    }
    int len = root_index - s2;
    root->left = createTree(preorder, s1 + 1, s1 + 1 + len - 1, inorder, s2, s2 + len - 1);
    root->right = createTree(preorder, s1 +len + 1, e1, inorder, root_index + 1, e2); 
    
    return root;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int end = preorder.size() - 1;
        return createTree(preorder, 0, end, inorder, 0, end);
    }
};