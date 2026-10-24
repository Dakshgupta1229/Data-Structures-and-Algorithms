class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int sum_peak = 0;
        int sum_valley = 0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) sum_peak += nums[i];
            if(nums[i]<nums[i-1] && nums[i]<nums[i+1]) sum_valley += nums[i];
        }
        return sum_peak - sum_valley;
    }
};