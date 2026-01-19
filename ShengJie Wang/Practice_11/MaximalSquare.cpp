
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int a = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0') {
                    dp[i + 1][j + 1] = 0;
                } else {
                    dp[i + 1][j + 1] = min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j])) + 1; 
                }
                a = max(a, dp[i + 1][j + 1]);
            }
        }
        return a * a;
    }
};