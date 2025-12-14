/* Climbing satirs */

//methon 1 :Top-down
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        return _helper(n, dp);
    }
    int _helper(int n, vector<int>& dp) {
        if(n < 2)
            return 1;

        if(!dp[n])
            dp[n] = _helper(n - 1, dp) + _helper(n - 2, dp);
        
        return dp[n];
    }
};

//methond2: Bottom-up
class Solution {
public:
    int climbStairs(int n) {
        if(n < 2)
            return n;
        int pre = 1, cur = 1;
        for(int i = 2; i <= n; i++){
            int next = pre + cur;
            pre = cur;
            cur = next;
        }
        return cur;
    }
};