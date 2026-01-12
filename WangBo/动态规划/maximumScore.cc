#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size();
        int m=multipliers.size();
        //左边i个 右边j个 i+j=m
        //首先考虑全左边或全右边
        vector<vector<int>> dp(m+1,vector<int>(m+1));
        //创建状态表,表示不同策略的分数
        int ret=0;
        for(int i=1; i<m+1 ; i++)
        {
            // 全左
            dp[i][0]=dp[i-1][0]+nums[i-1]*multipliers[i-1];
            //全右
            dp[0][i]=dp[0][i-1]+nums[n-i]*multipliers[i-1];
        }
        ret=max(dp[m][0],dp[0][m]);
        //左边i个 右边j个   i+j=m
        for(int i=1 ; i<m+1 ; i++)
        {
            for(int j=1 ; j<=m-i ; j++)
            {
                dp[i][j] = max(dp[i-1][j] + multipliers[i+j-1]*nums[i-1], \
                dp[i][j-1] + multipliers[i+j-1]*nums[n-j]);
                if(i+j==m)
                {
                    ret=max(ret,dp[i][j]);
                }
            }
        }
        return ret;
    }
};