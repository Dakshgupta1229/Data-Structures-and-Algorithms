class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int max_ele = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(max_ele<nums[i]) max_ele = nums[i];
        }
        for(int i=0;i<nums.size();i++){
            sum = sum + (max_ele - nums[i]);
        }
        return sum;
    }
};