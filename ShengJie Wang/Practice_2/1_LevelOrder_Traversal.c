/*
    Binary Tree Level Order Traversal
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    
        if(!root)
            return {};
        queue<TreeNode*>nodes;
        vector<vector<int>> ans;
        nodes.push(root);
        while(!nodes.empty()){
            int len=nodes.size();
            ans.push_back({});
            for(int i=0;i<len;i++){
                ans.back().push_back(nodes.front()->val);
                if(nodes.front()->left)   nodes.push(nodes.front()->left);
                if(nodes.front()->right)  nodes.push(nodes.front()->right);
                nodes.pop();
            }
        }
        return ans;
    }
};