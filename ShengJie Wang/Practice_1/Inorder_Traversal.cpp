// recursively
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        
        vector<int> left;
        vector<int> right;
        vector<int> ans;
        
        left = inorderTraversal(root->left);
        right = inorderTraversal(root->right);
        
        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(root->val);
        ans.insert(ans.end(), right.begin(), right.end());
        
        return ans;
        
    }
};

//iterately
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        
        vector<int> ans;
        stack<TreeNode*> tree_node;
        
        while(root || !tree_node.empty())
        {
            while(root)
            {
                tree_node.push(root);
                root = root->left;
            }
            
            if(!tree_node.empty())
            {
                root = tree_node.top();
                ans.push_back(root->val);
                tree_node.pop();
                root = root->right;
            }
        }
        return ans;
    }
};