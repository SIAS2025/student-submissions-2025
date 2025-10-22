#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//使用递归法 退出条件是找到叶子结点 且 路径和刚好减为0
class Solution {
public:
bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right && targetSum==root->val) return true;
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
    }
    };

//使用使用栈  
class Solution {
public:
bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        stack<pair<TreeNode*,int>> st;
        st.push(pair<TreeNode*,int >(root,targetSum));
        while(!st.empty())
        {
            pair<TreeNode*,int> cur=st.top();
            st.pop();
            if(!cur.first->left && !cur.first->right && cur.second==cur.first->val) return true;
            if(cur.first->left) st.push(pair<TreeNode*,int>(cur.first->left,cur.second-cur.first->val));
            if(cur.first->right) st.push(pair<TreeNode*,int>(cur.first->right,cur.second-cur.first->val));  
        }
        return false;
    }
    };