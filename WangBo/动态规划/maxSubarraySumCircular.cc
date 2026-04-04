class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int maxsum=nums[0];
        int maxfn=nums[0];
        int minsum=nums[0];
        int minfn=nums[0];
        int totalsum=nums[0];
        for(int i=1 ; i<n ; i++){
            totalsum+=nums[i];
            maxfn=max(nums[i],maxfn+nums[i]);
            maxsum=max(maxsum,maxfn);

            minfn=min(nums[i],minfn+nums[i]);
            minsum=min(minfn,minsum);
        }
        if(maxsum<0) return maxsum;
        return max(maxsum,totalsum-minsum);
    }
};