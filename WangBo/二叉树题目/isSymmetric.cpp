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

//利用层序遍历,逐层判断对称性
class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            if(!root) return true;
            queue<TreeNode*> que;
            que.push(root);
            que.push(root);
            while(!que.empty())
            {
                int size = que.size();
                for(;size>0;size-=2)
                {
                    TreeNode* first=que.front();
                    que.pop();
                    TreeNode* second=que.front();
                    que.pop();
                    if(first && !second) return false;
                    else if(!first && second) return false;
                    else if(!first && !second) continue;
                    else if(first->val != second->val) return false;
                    que.push(first->left);
                    que.push(second->right);
                    que.push(first->right);
                    que.push(second->left);
                }
            }
            return true;
        }
    };

//利用递归的方法  top -> down  逐个递归对比左右节点是否对称
class Solution {
    public:
        bool isSymmetric(TreeNode* left,TreeNode* right)
        {
            if(!left && right)
            {
                return false;
            }
            else if(left && !right)
            {
                return false;
            }
            else if(!left && !right)
            {
                return true;
            }
            else if(left->val != right->val) return false;
            return isSymmetric(left->left,right->right)&&isSymmetric(left->right,right->left);
        }
        bool isSymmetric(TreeNode* root) {
            if(!root) return true;
            return isSymmetric(root->left,root->right);
        }
    };