class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int m = grid.size();    //行数
        int n = grid[0].size(); //列数
        int count = 0;  //岛数

        vector<pair<int,int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};

        for (int i=0; i<m; i++){
            for (int j = 0;j<n;j++){
                if (grid[i][j] == '1') { // 发现未访问的陆地
                    ++count;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0'; // 标记为已访问
                    
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        
                        // 遍历四个方向
                        for (auto [dx, dy] : dirs) {
                            int nx = x + dx;
                            int ny = y + dy;
                            // 检查新坐标是否在网格内，且是未访问的陆地
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                                q.push({nx, ny});
                                grid[nx][ny] = '0'; // 标记为已访问
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
