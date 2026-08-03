class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i] + nums[i-1];
        }
        int idx = -1;
        int min_ele = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(min_ele>nums[i]){
                min_ele = nums[i];
                idx = i;
            }
        }
        if(min_ele<0) return abs(min_ele) + 1;
        return 1;
    }
};