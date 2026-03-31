class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len_max = 0;
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            len_max = max(len_max, dp[i]);
        }
        return len_max;
    }
};