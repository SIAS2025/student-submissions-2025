#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//down to top
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        sort(nums.begin(),nums.end());
        vector<int> remove(n);
        vector<int> not_remove(n);
        remove[0]=nums[0];
        not_remove[0]=0;
        for(int i=1 ; i<n ; i++)
        {
            if(nums[i]>nums[i-1]+1) //前面的不影响当前的
            {
                remove[i]=max(remove[i-1] , not_remove[i-1]) + nums[i];
                not_remove[i]=max(remove[i-1],not_remove[i-1]);
            }
            else if(nums[i]==nums[i-1]+1) //前面的会影响当前的
            {
                remove[i]=not_remove[i-1]+nums[i];
                not_remove[i]=max(remove[i-1],not_remove[i-1]);
            }
            else if(nums[i]==nums[i-1]) //前面的不会影响当前的
            {
                // remove[i]=max(remove[i-1],not_remove[i-1])+nums[i];
                // not_remove[i]=max(remove[i-1],not_remove[i-1]);
                remove[i]=remove[i-1]+nums[i];
                not_remove[i]=not_remove[i-1];
            }
        }
        return max(remove[n-1],not_remove[n-1]);
    }
};

//leetcode official solution
//down to top 退化为打家劫舍问题去做
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        //统计nums中的数
        vector<int> vec;
        int max_val=0;
        for(auto i:nums)
        {
            max_val=max(max_val,i);
        }
        vec.resize(max_val+1);
        for(auto i:nums)
        {
            vec[i]+=i;
        }
        //现在得到一个数组,退化为打家劫舍问题
        vector<int> status(max_val+1);
        status[0]=vec[0];
        status[1]=max(status[0],vec[1]);
        for(int i=2 ; i<=max_val;i++)
        {
            status[i]=max(status[i-1],status[i-2]+vec[i]);
        }
        return status[max_val];
    }
};
