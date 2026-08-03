class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0;
        int i=0;
        int j=0;
        int max_len = INT_MIN;
        while(j<nums.size()){
            if(nums[j]==0) count++;
            while(count>1){
                if(max_len<(j-i-1)) max_len = j - i - 1;
                if(nums[i]==0) count--;
                i++;
            }
            j++;
        }
        if(max_len<(j-i-1)) max_len = j - i - 1;
        return max_len;
    }
};