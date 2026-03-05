class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //dp[hoding][tranc_count]
        vector<vector<int>> dp(2, vector<int>(k + 1, 0));
        dp[0][0] = 0;
        dp[1][0] = -prices[0]; 
        k = min(k, n / 2);
        for (int m = 1; m <= k; m++) {
            dp[0][m] = dp[1][m] = INT_MIN / 2;
        }
        for(int i = 1; i < n; i++) {
            dp[1][0] = max(dp[0][0] - prices[i], dp[1][0]);
            for(int j = 1; j <= k; j++) {
                dp[0][j] = max(dp[1][j - 1] + prices[i], dp[0][j]);
                dp[1][j] = max(dp[0][j] - prices[i], dp[1][j]);
            } 
        }

        return *max_element(dp[0].begin(), dp[0].end());
    }
};