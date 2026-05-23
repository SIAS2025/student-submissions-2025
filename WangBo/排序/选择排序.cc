class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==0) return;
        int min_index=0;
        int cur;
        for(int i =0 ; i<nums.size()-1 ; i++){
            cur=i;
            min_index=i;
            for(int j=i ; j<nums.size() ; j++){
                if(nums[j]<nums[min_index]){
                    min_index=j;
                }
            }
            if(min_index!=i){
                swap(nums[i],nums[min_index]);
            }
        }
        
    }
};
