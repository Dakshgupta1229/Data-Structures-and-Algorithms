class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int ele = nums[0];
        int count = 1;
        int result = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==ele) count++;
            else{
                ele = nums[i];
                count = 1;
            }
            if(count>1) result++;
        }
        return result;
    }
};