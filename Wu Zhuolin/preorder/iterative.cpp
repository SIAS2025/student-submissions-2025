/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        stack<TreeNode*> stk;
        stk.push(root); // 将根节点入栈

        // 当栈不为空时，持续循环
        while (!stk.empty()) {
            // 1. 弹出栈顶节点
            TreeNode* node = stk.top();
            stk.pop();

            // 2. 访问该节点（根）
            result.push_back(node->val);

            // 3. 压入右子节点和左子节点
            if (node->right != nullptr) {
                stk.push(node->right);
            }
            if (node->left != nullptr) {
                stk.push(node->left);
            }
        }

        return result;
    }
};
