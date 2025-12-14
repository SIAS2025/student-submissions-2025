/* N-th Tribonacci Number */

//method 1: Top-down
class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);
        return _helper(dp, n);
    }
    
    int _helper(vector<int>& dp, int n) {  // 改为引用传递
        if (n < 2) return n;
        if (n == 2) return 1;
        
        if (dp[n] != -1) return dp[n];
        
        dp[n] = _helper(dp, n - 3) + _helper(dp, n - 2) + _helper(dp, n - 1);
        return dp[n];
    }
};

//method 2: Bottom-up
class Solution {
public:
    int tribonacci(int n) {
        if(n < 2)   return n;
        if(n == 2)  return 1;
        int pre2 = 0, pre1 = 1, cur = 1;
        for(int i = 3; i <= n; i++){
            int next = pre2 + pre1 + cur;
            pre2 = pre1;
            pre1 = cur;
            cur = next;
        }
        return cur;
    }
};