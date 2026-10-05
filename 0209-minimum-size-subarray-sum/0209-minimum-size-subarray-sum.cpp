class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int sum = 0;
        int min_length = INT_MAX;
        while(i<nums.size()){
            sum = sum + nums[i];
            while(sum>=target){
                if(min_length>(i-j+1)) min_length = i-j+1;
                sum = sum - nums[j];
                j++;
            }
            i++;
        }
        if(min_length==INT_MAX) return 0;
        return min_length;
    }
};