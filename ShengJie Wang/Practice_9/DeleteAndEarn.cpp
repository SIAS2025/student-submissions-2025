class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int len = nums.size();

        if (len < 2) {
            return nums[0];
        }

        sort(nums.begin(), nums.end());

        int max_deleted, max_deleted_last;
        int max_passed, max_passed_last;
        max_deleted = max_deleted_last = nums[0];
        max_passed = max_passed_last = 0;
        for(int i = 1; i < nums.size(); i++) {
            if ( nums[i - 1] < nums[i] - 1) {
                // 不连续且有间隔， 直接计算
                max_passed = max(max_passed_last, max_deleted_last);
                max_deleted = max(max_passed_last, max_deleted_last) + nums[i];
            } else if (nums[i - 1] == nums[i] - 1){
                // 连续，删除当前必须跳过前一个
                max_passed = max(max_passed_last, max_deleted_last);
                max_deleted = max_passed_last + nums[i];
            } else {
                //相等，取得max eran时，相同数值操作一定一样（保证后续计算正确） 
                max_passed= max_passed_last;
                max_deleted = max_deleted_last + nums[i];
            }
            max_passed_last = max_passed;
            max_deleted_last = max_deleted;
        }
        return max(max_deleted, max_passed);
    }
};