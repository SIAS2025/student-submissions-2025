class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();  //行数
        int cols = matrix[0].size(); //列数
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        int max_side = 0; // 记录最大正方形的边长
        for (int i=0;i<rows;i++){       //遍历每个元素
            for (int j=0;j<cols;j++){
                if (matrix[i][j]=='1'){
                    // 用i+1/j+1访问dp，无需单独处理i=0/j=0的边界
                    dp[i+1][j+1] = min(min(dp[i][j+1], dp[i+1][j]), dp[i][j]) + 1;
                    // 都更新max_side
                    max_side = max(max_side, dp[i+1][j+1]);
                }
            }
        }
        return max_side*max_side;
    }
};
