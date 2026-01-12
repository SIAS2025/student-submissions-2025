

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int len1 = nums.size();
        int len2 = multipliers.size();
        vector<int> temp(len2  + 1,0);
        vector<vector<int>> dp(len2 + 1,temp);
        dp[0][0] = 0;
        // 处理起始条件
        for(int i = 1; i < len2 + 1; i++) {
            dp[0][i] = dp[0][i - 1] + multipliers[i - 1] * nums[len1 - i];
            dp[i][0] = dp[i - 1][0] + multipliers[i - 1] * nums[i - 1];
        }
        int ans = max(dp[0][len2], dp[len2][0]);
        for(int j = 1; j < len2 + 1; j++) {
            for(int k = 1; j + k < len2 + 1; k++) {
                dp[j][k] = max(dp[j - 1][k] + nums[j - 1] * multipliers[j + k - 1], dp[j][k - 1] + nums[len1 - k] * multipliers[j + k - 1]);

                if(j + k == len2) {
                    ans = max(ans, dp[j][k]);
                }
            }
        }
        return ans;
    }
};