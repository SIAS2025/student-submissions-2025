package DP;

public class MaximumScoreFromPerformingMultiplicationOperations {
    public int maximumScore(int[] nums, int[] multipliers) {
        int m = multipliers.length;
        int n = nums.length;
        int[][] dp = new int[m + 1][m + 1];
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] + nums[i - 1] * multipliers[i - 1];
            dp[0][i] = dp[0][i - 1] + nums[n - i] * multipliers[i - 1];
        }
        int ans = Math.max(dp[0][m], dp[m][0]);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                if (i + j > m) continue;
                dp[i][j] = Math.max(dp[i - 1][j] + nums[i - 1] * multipliers[i + j - 1],
                        dp[i][j - 1] + nums[n - j] * multipliers[i + j - 1]);
                if (i + j == m) {
                    ans = Math.max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
}
