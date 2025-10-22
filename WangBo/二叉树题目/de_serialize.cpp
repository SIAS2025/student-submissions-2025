#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <string>
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


class Codec {
public:
    void preorder(TreeNode* node,string &res)
    {
        if(!node)
        {
            res+="NULL,";
            return ;
        }
        else
        {
            res+=to_string(node->val)+",";
        }
        preorder(node->left,res);
        preorder(node->right,res);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res;
        preorder(root,res);
        return res;
    }

    TreeNode* de(queue<string> & array)
    {
        if(array.front()=="NULL") 
        {
            array.pop();
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(array.front()));
        array.pop();
        root->left=de(array);
        root->right=de(array);
        return root; 
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        queue<string> dataarray;
        string str;
        for(int i=0;i<data.size();i++)
        {
            if(data[i]==',')
            {
                dataarray.push(str);
                str.clear();
            }
            else
            {
                str+=data[i];
            }
        }
        return de(dataarray);
    }
};