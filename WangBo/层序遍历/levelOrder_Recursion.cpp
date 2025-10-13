#include <vector>
#include <iostream>
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

//使用递归法的层序遍历
class Solution {
public:
    void insertval(TreeNode* root,int level,vector<vector<int>> &res)
    {
        if (!root)
        {
            return ;
        }
        if (level>=res.size())//新的一层
        {
            res.push_back(vector<int>());
        }
        res[level].push_back(root->val);
        insertval(root->left,level+1,res);//从左到右遍历叶子节点
        insertval(root->right,level+1,res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        insertval(root,0,res);
        return res;
    }
};