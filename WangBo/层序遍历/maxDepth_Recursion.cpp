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

//使用递归法求二叉树的最大深度
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (!root)
            {
                return 0;
            }
            traversal(root,1);
            return depth;
        }
    private:
        int depth=0;
        void traversal(TreeNode* root,int level)
        {
            if (!root)
            {
                return ;
            }
            if(root->left==NULL && root->right==NULL)//叶子节点
            {
                depth=max(depth,level);
                return ;
            }
            traversal(root->left,level+1);
            traversal(root->right,level+1);
        }
    };