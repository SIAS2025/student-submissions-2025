// recursively
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        //insert root
        vector<int> ans;
        ans.push_back(root->val);
        //insert left
        vector<int> left = preorderTraversal(root->left);
        ans.insert(ans.end(), left.begin(), left.end());
        //insert right
        vector<int> right = preorderTraversal(root->right);
        ans.insert(ans.end(), right.begin(), right.end());
        
        return ans;       
    }
};

//iterately
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> ans;
        stack<TreeNode*> tree_node;

        while(root || !tree_node.empty())
        {
            while(root)
            {
                tree_node.push(root);
                ans.push_back(root->val);
                root = root->left;
            }

            if(!tree_node.empty())
            {
                root = tree_node.top()->right;
                tree_node.pop();
            }
            
        }
        
        return ans;
    }
};