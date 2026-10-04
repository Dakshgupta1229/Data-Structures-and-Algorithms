class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            int correct_idx = nums[i];
            if(i==correct_idx) i++;
            else if(correct_idx>=nums.size()) i++;
            else swap(nums[correct_idx],nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(i!=nums[i]) return i;
        }
        return nums.size();
    }
};