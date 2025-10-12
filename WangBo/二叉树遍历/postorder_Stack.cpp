#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
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

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (!root)
        {
            return res;
        }
        st.push(root);
        while (!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);//中
            if (node->left)
            {
                st.push(node->left);//左
            }
            if (node->right)
            {
                st.push(node->right);//右
            }
        }//出来是中右左
        //翻转 左右中 后序
        reverse(res.begin(),res.end());
        return res;
    }
};