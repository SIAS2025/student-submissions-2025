class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(3, 0);
        int n = cost.size();
        dp[0] = dp[1] = 0;

        for(int j = 2; j <= n; j++) {
            dp[0] = dp[1];
            int temp = dp[2];
            dp[2] = min(dp[1] + cost[j - 2], dp[2] + cost[j - 1]);
            dp[1] = temp;
        }
        return dp[2];
    }
};