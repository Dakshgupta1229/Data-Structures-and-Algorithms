class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            int correct_pos = nums[i];
            if(nums[i]>=nums.size()) i++;
            else if(i!=correct_pos) swap(nums[i],nums[correct_pos]);
            else i++;
        }
        for(int i=0;i<nums.size();i++){
            if(i!=nums[i]) return i;
        }
        return nums.size();
    }
};