class Solution {
public:
    int minStartValue(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i] + nums[i-1];
        }
        int min_ele = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(min_ele>nums[i] && nums[i]<0){
                min_ele = nums[i];
            }
        }
        if(min_ele==INT_MAX) return 1;
        return abs(min_ele) + 1;
    }
};