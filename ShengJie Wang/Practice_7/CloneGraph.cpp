class Solution {
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        if(visited.find(node) != visited.end())
            return visited[node];
        Node* cpy = new Node(node->val);
        visited[node] = cpy;
        for(auto& neigh : node->neighbors){
            cpy->neighbors.push_back(cloneGraph(neigh));
        }
        return cpy;
    }
};