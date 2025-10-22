/*
    Populating Next Right Pointers in Each Node
    perfect binary tree
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return nullptr;
        Node* level_head = root;
        
        while(level_head->left)
        {
            Node* cur_node = level_head;
            while(cur_node)
            {
                cur_node->left->next = cur_node->right;
                if(cur_node->next)
                    cur_node->right->next = cur_node->next->left;
                cur_node = cur_node->next;
            }
            level_head = level_head->left;
        }
        return root;
    }
};