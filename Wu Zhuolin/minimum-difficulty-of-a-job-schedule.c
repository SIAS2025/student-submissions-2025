class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        // 任务数小于天数，无法分配，直接返回-1
        if (n < d) {
            return -1;
        }

        // dp[i][j] 表示前i天完成前j个工作的最小难度
        vector<vector<int>> dp(d + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0; // 初始状态：0天完成0个工作难度为0

        for (int i = 1; i <= d; ++i) {
            for (int j = i; j <= n; ++j) {
                int maxDiff = 0;
                // 倒着找第i天的任务分界点
                for (int k = j - 1; k >= i - 1; --k) {
                    maxDiff = max(maxDiff, jobDifficulty[k]);
                    if (dp[i - 1][k] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + maxDiff);
                    }
                }
            }
        }

        return dp[d][n] == INT_MAX ? -1 : dp[d][n];
    }
};
