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

//使用层序遍历求二叉树的最大深度
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (!root)
            {
                return 0;
            }
            queue<TreeNode*> q;//使用队列当做暂存容器 先进先出
            q.push(root);
            int depth=0;
            while (!q.empty())
            {
                int size=q.size();
                depth++;
                for (int i = 0; i < size; i++)
                {
                    TreeNode* node=q.front();
                    q.pop();
                    if (node->left)
                    {
                        q.push(node->left);
                    }
                    if (node->right)
                    {
                        q.push(node->right);
                    }
                }
            }
            return depth;
        }
    };