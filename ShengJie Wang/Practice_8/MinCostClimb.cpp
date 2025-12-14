/* Min Cost Climbing Stairs*/

//method 1: Top-down
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> dp(len, -1);
        return min(_helper(cost, dp, len - 1), _helper(cost, dp, len - 2));
    }
    int _helper(vector<int>& cost, vector<int>& dp, int n){
        if(n < 2)
            return cost[n];
        
        if(dp[n] == -1)
            dp[n] = min(_helper(cost, dp, n - 1), _helper(cost, dp, n - 2)) + cost[n];
        
            return dp[n];
    }
};

//method 12: Botton-up
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int pre = 0, cur = 0;
        for(int& _cost : cost){
            int next = _cost + min(pre, cur);
            pre = cur;
            cur = next;
        }
        return min(cur, pre);
    }
};