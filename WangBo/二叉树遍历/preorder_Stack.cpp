#include <vector>
#include <iostream>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode* root) {
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
            res.push_back(node->val);//前
            if (node->right)
            {
                st.push(node->right);//右 后出先入
            }
            if (node->left)
            {
                st.push(node->left);
            }
        }
        return res;
    }
};