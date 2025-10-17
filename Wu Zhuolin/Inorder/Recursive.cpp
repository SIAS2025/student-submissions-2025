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
        traverse(root, result);
        return result;
    }

private:
    // 3. 定义递归函数
    void traverse(TreeNode* node, vector<int>& result) {
        // 递归终止条件：节点为空
        if (node == nullptr) {
            return;
        }

                
        // a. 递归遍历左子树
        traverse(node->left, result);
        
        // b. 访问当前根节点，将其值加入结果
        result.push_back(node->val);

        // c. 递归遍历右子树
        traverse(node->right, result);
    }
};
