/*
    Serialize and Deserialize Binary Tree
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //先序遍历
        if(!root)
            return "#";
        // ss输出时按空格分割，自动类型转换
        return to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right); 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return deserialize_helper(ss);

    }

    TreeNode* deserialize_helper(istringstream &ss)         //istringstream的拷贝构造函数被显式删除（delete），不能按值传递。
    {
        string temp;
        ss >> temp;
        if(temp == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(temp));
        root->left = deserialize_helper(ss);
        root->right = deserialize_helper(ss);
        return root;
    }
};