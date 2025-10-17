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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        stack<TreeNode*> stk;
        TreeNode* curr = root; // 用curr跟踪当前节点，初始指向根

        // 循环条件：当前节点不为空 或 栈不为空（确保所有节点都被处理）
        while (curr != nullptr || !stk.empty()) {
            // 1. 先遍历到最左侧节点，沿途节点入栈（左子树优先）
            while (curr != nullptr) {
                stk.push(curr); // 暂存当前节点（未来作为“根”访问）
                curr = curr->left; // 继续向左深入
            }

            // 2. 左子树为空，弹出栈顶节点（此时为“根”）并访问
            curr = stk.top();
            stk.pop();
            result.push_back(curr->val); // 访问根节点

            // 3. 转向右子树，重复上述过程（处理右子树）
            curr = curr->right;
        }

        return result;
    }
};
