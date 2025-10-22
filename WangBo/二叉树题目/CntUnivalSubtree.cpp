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

//后序遍历 先找叶子结点 在往上判断中节点 
class Solution {
public:
bool isUnivalSubtree(TreeNode* node,int& res)
{
    if (!node) return true;
    if(node->left) bool left=isUnivalSubtree(node->left,res);
    if(node->right) bool right=isUnivalSubtree(node->right,res);
    if(left && right)
    {
        if(node->left && node->val!=node->left->val) return false;
        if(node->right && node->val!=node->right->val) return false;
        res++;
        return true;
    }
    return false;
}
int cntUnivalSubtree(TreeNode* root) {
        if(!root) return 0;
        int res=0;
        isUnivalSubtree(root,res);
        return res;
    }
};