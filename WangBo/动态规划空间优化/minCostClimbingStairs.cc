//dp[i]=min(dp[i-1]+dp[i-2])+cost[i]  
//这种是down to top的思路 , 通过状态转移方程和初值,推进到终值返回
//使用dp数组存放中间状态,空间复杂度为O(n),使用rolling state,空间复杂度降为O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==0) return 0;
        if(n==1) return cost[0];
        if(n==2) return min(cost[0],cost[1]);
        //vector<int> dp(n,0);
        int fn1=cost[0];
        int fn2=cost[1];
        int fn=0;
        for(int i=2 ; i<n ; i++)
        {
            fn=min(fn1,fn2)+cost[i];
            fn1=fn2;
            fn2=fn;
        }
        return min(fn1,fn2);
    }
};




//top to down
//思路:f(n)=min(f(n-1)+cost(n-1),f(n-2)+cost(n-2))
//返回条件:f(0)=0  f(1)=0
//方法:使用递归+记忆存储的方法
// class Solution {
// public:
//     int dfs(int n,vector<int>& status,vector<int>& cost)
//     {
//         if(n==0 || n==1) return 0;
//         if(status[n]!=-1) return status[n];
//         status[n]=min(dfs(n-1,status,cost)+cost[n-1],dfs(n-2,status,cost)+cost[n-2]);
//         return status[n];
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         vector<int> status(n+1,-1);
//         return dfs(n,status,cost);
//     }
// };