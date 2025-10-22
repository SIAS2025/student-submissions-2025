#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//层序遍历法
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            for(int i=0;i<size;i++)
            {
                Node* cur=que.front();
                que.pop();
                if(i!=size-1)
                {
                    Node* next_=que.front();
                    cur->next=next_;
                }
                else
                {
                    cur->next=NULL;
                }
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return root;
    }
};

//直接法-另一种层序思想
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* leftmost= root;
        while(leftmost->left)
        {
            Node* head=leftmost;
            while(head)
            {
                head->left->next=head->right;
                if(head->next)
                {
                    head->right->next=head->next->left;
                }
                head=head->next;
            }
            leftmost=leftmost->left;
        }
        return root;
    }
};