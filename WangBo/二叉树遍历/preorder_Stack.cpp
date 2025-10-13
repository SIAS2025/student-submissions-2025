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

//一种通用的迭代遍历方法   标记法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode*,bool>> st;
        if (!root)
        {
            return res;
        }
        st.push(make_pair(root,false));//false表示该节点还未被处理
        while (!st.empty())
        {
            TreeNode* node = st.top().first;
            bool flag = st.top().second;
            st.pop();
            if (flag)//该节点已经被处理
            {
                res.push_back(node->val);
            }
            else//该节点还未被处理
            {
                if (node->right)//右
                {
                    st.push(make_pair(node->right,false));
                }
                if (node->left)//左
                {
                    st.push(make_pair(node->left,false));
                }
                st.push(make_pair(node,true));//中   标记该节点已经被处理
            }
        }
        return res;
    }
};