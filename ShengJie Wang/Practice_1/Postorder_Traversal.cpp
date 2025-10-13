// recursively
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        
        vector<int> ans;
        vector<int> left;
        vector<int> right;
        
        left = postorderTraversal(root->left);
        right = postorderTraversal(root->right);
        
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), right.begin(), right.end());
        ans.push_back(root->val);
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
        TreeNode* seeing_node = nullptr;        //当前节点
        TreeNode* seen_node = nullptr;          //记录上一个遍历过的节点
        while(root || !tree_node.empty())
        {
            while(root)
            {
                tree_node.push(root);
                root = root->left;
            }
            
            //如果该节点的右节点等于上一个遍历过的节点，那么说明该节点的右子树已经遍历过
            seeing_node = tree_node.top();
            if(seeing_node->right && seeing_node->right != seen_node)
            {
                root = seeing_node->right;
            }
            else
            {
                ans.push_back(seeing_node->val);
                tree_node.pop();
                seen_node = seeing_node;
            }
                
        }
        return ans;
    }
};