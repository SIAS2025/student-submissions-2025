#include <iostream>
#include <vector>
using namespace std;

//暴力法O(2^n)递归 top to down
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return fib(n-1)+fib(n-2);
    }
};

//top to down
//记忆优化递归复杂度 O(n)
class Solution {
public:
    int dfs(int n , vector<int>& status)
    {
        if(status[n]!=-1) return status[n];
        status[n]=dfs(n-1,status)+dfs(n-2,status);
        return status[n];
    }
    int fib(int n) {
        if(n==0) return 0;
        vector<int>status(n+1,-1);
        status[0]=0;
        status[1]=1;
        return dfs(n,status);
    }
};

//down to top
//思路: f(n)=f(n-1)+f(n-2)
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int f0=0;
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