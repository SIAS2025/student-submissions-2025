/* Number of Islands */

class Solution {
    vector<vector<int>>directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void de_Island(vector<vector<char>>& grid, int x, int y){
        queue<pair<int, int>> que;
        int len = grid.size();
        int width = grid[0].size();
        que.push(make_pair(x, y));
        grid[x][y] = '0';
        while(!que.empty()){
            pair<int, int> cur = que.front();
            que.pop();
            for(auto dir : directions){
                int new_x = cur.first + dir[0];
                int new_y = cur.second + dir[1];
                
                if(new_x >= 0 && new_x < len && new_y >= 0 && new_y < width && grid[new_x][new_y] == '1'){
                    grid[new_x][ new_y] = '0';
                    que.push(make_pair(new_x, new_y));
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int len = grid.size();
        int width = grid[0].size();
        int ans = 0;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < width; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    de_Island(grid, i, j);
                }
            }
        }
        return ans;
    }
};