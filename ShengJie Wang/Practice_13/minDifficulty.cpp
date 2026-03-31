class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int len = jobDifficulty.size();
        if (len < d) {
            return -1;
        }
        vector<vector<int>> dp(len + 1, vector<int>(d + 1, INT_MAX / 2));
        dp[0][0] = 0;

        for(int day = 1; day <= d; day++) {
            for(int i = day; i <= len; i++) {
                int diffi = 0;
                for (int l = i; l >= day; l--) {
                    diffi = max(diffi, jobDifficulty[l - 1]);
                    if (dp[l - 1][day - 1] != INT_MAX / 2) {
                       dp[i][day] = min(dp[i][day], dp[l - 1][day - 1] + diffi); 
                    }
                }
            }
        }
        return dp[len][d];
    }
};