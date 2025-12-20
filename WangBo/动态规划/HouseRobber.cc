#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// down to top
// fn=max[f(n-2)+nums[n],f(n-1)]
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> status(n+1);
        status[0]=0;
        status[1]=nums[0];
        for(int i=2 ;i<=n;i++)
        {
            status[i]=max(status[i-2]+nums[i-1],status[i-1]);
        }
        return status[n];
    }
};

//top to down
class Solution {
public:
    int dfs(vector<int> &status , int n,vector<int> &nums)
    {
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(status[n]!=-1) return status[n];
        status[n]=max(dfs(status,n-2,nums)+nums[n-1],dfs(status,n-1,nums));
        return status[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> status(n+1,-1);
        status[0]=0;
        status[1]=nums[0];
        return dfs(status,n,nums);
    }
};
