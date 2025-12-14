
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<Node*,Node*> visited;
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        //已经复制
        if(visited.find(node)!= visited.end())
        {
            return visited[node];
        }
        //未复制
        //深拷贝
        Node* cnode=new Node(node->val);
        visited[node]=cnode;
        for(int i=0 ; i<node->neighbors.size();i++)
        {
            cnode->neighbors.emplace_back(cloneGraph(node->neighbors[i]));
        }
        return cnode;
    }
};
