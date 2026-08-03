class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        long long sum = 0;
        int min_length = INT_MAX;
        while(j<nums.size()){
            if(sum<(long long)target) sum = sum + (long long)nums[j];
            while(sum>=target){
                if(sum>=target){
                    int idx = j-i+1;
                    if(min_length>idx) min_length = idx;
                }
                sum = sum - nums[i];
                i++;
            }
            j++;
        }
        while(sum>=target && i<nums.size()){
                if(sum>=target){
                    int idx = j-i+1;
                    if(min_length>idx) min_length = idx;
                }
                sum = sum - nums[i];
                i++;
        }
        if(min_length==INT_MAX) return 0;
        return min_length;
    }
};