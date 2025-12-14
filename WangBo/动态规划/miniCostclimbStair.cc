#include <vector>
using namespace std;
//down to top
//思路: f(n)=min(f(n-1)+cost(n-1),f(n-2)+cost(n-2))
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==0) return 0;
        if(n==1) return cost[0];
        int f0=0;
        int f1=0;
        int fx=0;
        for(int i=2;i<=n;i++)
        {
            fx=min(f0+cost[i-2],f1+cost[i-1]);
            f0=f1;
            f1=fx;
        }
        return fx;
    }
};

//top to down
//思路:f(n)=min(f(n-1)+cost(n-1),f(n-2)+cost(n-2))
//返回条件:f(0)=0  f(1)=0
//方法:使用递归+记忆存储的方法
class Solution {
public:
    int dfs(int n,vector<int>& status,vector<int>& cost)
    {
        if(n==0 || n==1) return 0;
        if(status[n]!=-1) return status[n];
        status[n]=min(dfs(n-1,status,cost)+cost[n-1],dfs(n-2,status,cost)+cost[n-2]);
        return status[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> status(n+1,-1);
        return dfs(n,status,cost);
    }
};