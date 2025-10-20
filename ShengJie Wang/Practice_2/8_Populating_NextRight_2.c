/*
    Populating Next Right Pointers in Each Node
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return nullptr;
        Node *head = new Node(0), *cur = head;
        Node* upper_node = root;
        while(upper_node)
        {
            if(upper_node->left){
                cur->next = upper_node->left;
                cur = cur->next;
            }
            if(upper_node->right){
                cur->next = upper_node->right;
                cur = cur->next;
            }
            upper_node = upper_node->next;
            if(!upper_node)
            {
                upper_node = head->next;
                head = new Node(0);
                cur = head;
            }
        }
        return root;
    }
};