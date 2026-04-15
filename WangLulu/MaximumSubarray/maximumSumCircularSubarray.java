package WangLulu.MaximumSubarray;

public class maximumSumCircularSubarray {
        public int maxSubarraySumCircular(int[] nums) {
        int max = 0;
        int maxsum = nums[0];
        int min = 0;
        int minsum = nums[0];
        int totalsum = 0;
        for(int i = 0;i<nums.length;i++){
            totalsum += nums[i];
            max = Math.max(nums[i],nums[i]+max);
            maxsum = Math.max(max,maxsum);
            min = Math.min(nums[i],nums[i]+min);
            minsum = Math.min(min,minsum);
        }
         if(maxsum<0){
                return maxsum;
        }
        return Math.max(maxsum,totalsum-minsum);
    }
}
