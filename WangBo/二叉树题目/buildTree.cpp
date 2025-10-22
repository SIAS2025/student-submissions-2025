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

//使用递归的办法 重点是将左子树和右子树的中序和后序拆出来 传入递归
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return nullptr;
        int val=postorder.back();
        TreeNode* root=new TreeNode(val);
        vector<int> inorder_left;
        vector<int> inorder_right;
        vector<int> postorder_left;
        vector<int> postorder_right;
        int i = 0;
        for( ; i<inorder.size();i++)
        {
            if(inorder[i]==val) break;
        }
        //左子树中序
        for(int j=0;j<i;j++)
        {
            inorder_left.push_back(inorder[j]);
        }
        //右子树中序
        for(int j=i+1;j<inorder.size();j++)
        {
            inorder_right.push_back(inorder[j]);
        }
        //左子树后序
        for(int j=0;j<i;j++)
        {
            postorder_left.push_back(postorder[j]);
        }
        for(int j=i;j<postorder.size()-1;j++)
        {
            postorder_right.push_back(postorder[j]);
        }
        root->left=buildTree(inorder_left,postorder_left);
        root->right=buildTree(inorder_right,postorder_right);
        return root;
    }
};