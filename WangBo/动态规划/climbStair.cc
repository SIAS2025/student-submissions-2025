#include <vector>
using namespace std;

//down to top    
//解题思路 f(n)=f(n-1)+f(n-2)
//初始条件 f(0)=1 f(1)=1
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        int f0=1;
        int f1=1;
        int fx=0;
        for(int i=2;i<=n;i++)
        {
            fx=f0+f1;
            f0=f1;
            f1=fx;
        }
        return fx;
    }
};

//top to down
//思路：顶层n开始往下递归 
//问题：递归的时间复杂度O（2^n）,存在多次重复计算
//解决：通过把每一层的计算结果存在表中，规避重复计算降为O（n）
class Solution {
public:
    int dfs(int n,vector<int>&status)
    {
        if(n==0 || n==1) return 1;
        if(status[n] != -1) return status[n];
        status[n]=dfs(n-1,status)+dfs(n-2,status);
        return status[n];
    }
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        vector<int> status(n+1,-1);
        return dfs(n,status);
    }
};