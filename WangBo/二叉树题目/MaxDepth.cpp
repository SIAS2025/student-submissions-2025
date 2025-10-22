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

//最简单的可以用层序遍历求
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int res=0;
        while(!que.empty())
        {
            res++;
            int size=que.size();
            for(;size>0;size--)
            {
                TreeNode* cur=que.front();
                que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return res; 
    }
};

//使用递归 top -> down
class Solution {
public:
    int maxdp=0;
    void maxDepth(TreeNode* node,int level)
    {
        if(!node->left && !node->right)
        {
            maxdp=max(maxdp,level);
            return;
        }
        if(node->left) maxDepth(node->left,level+1);
        if(node->right) maxDepth(node->right,level+1);
        return;
    }

    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        maxDepth(root,1);
        return maxdp;
    }
};

//使用递归 down -> top
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return  max(maxDepth(root->left)+1,maxDepth(root->right)+1);
    }
};