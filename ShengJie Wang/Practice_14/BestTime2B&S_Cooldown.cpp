class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //0:持有  1:卖出  2:不持有且无行动
        vector<int> dp(3, 0);

        dp[0] = -prices[0];

        for(int i = 1; i < n; i++) {
            int dp0 = max(dp[0], dp[2] - prices[i]);
            int dp1 = dp[0] + prices[i];
            int dp2 = max(dp[1], dp[2]);
            dp[0] = dp0;
            dp[1] = dp1;
            dp[2] = dp2;
        }
        return max(dp[1], dp[2]);
    }
};