class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum_to = nums[0], min_sum_to = nums[0], total = nums[0];
        int min_sum = nums[0], max_sum = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            max_sum_to = max(max_sum_to + nums[i], nums[i]);
            min_sum_to = min(min_sum_to + nums[i], nums[i]);
            max_sum = max(max_sum_to, max_sum);
            min_sum = min(min_sum_to, min_sum);
            total = total += nums[i];
        }
        int ans = max_sum > 0 ? max(max_sum, total - min_sum) : max_sum;
        return ans;
    }
};