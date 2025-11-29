class Solution {
    vector<vector<int>> actions = {{0, 0, 0, 1}, {0, 0, 0, -1}, {0, 0, 1, 0}, {0, 0, -1, 0}, {0, 1, 0, 0}, {0, -1, 0, 0}, {1, 0, 0, 0}, {-1, 0, 0, 0}};
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_map<string, int> visited;
        queue<string> que;
        
        if (deads.count("0000")) return -1;
        que.push("0000");
        visited["0000"] = 0;
        while(!que.empty()){
            auto cur = que.front();
            que.pop();
            if(cur == target)   return visited[cur];
            for(int i = 0; i < 8; i++){
                auto next = cur;
                int j = 0; 
                while(j < 4 && actions[i][j] == 0)    j++;
                if (actions[i][j] == 1) {
                    next[j] = (next[j] == '9') ? '0' : next[j] + 1;
                } else {
                    next[j] = (next[j] == '0') ? '9' : next[j] - 1;
                }
                
                if(deads.find(next) != deads.end()){
                    continue;
                }
                if(visited.find(next) == visited.end()){
                    que.push(next);
                    visited[next] = visited[cur] + 1;
                }
            }
        }
        return -1;
    }
};