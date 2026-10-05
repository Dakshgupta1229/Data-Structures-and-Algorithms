class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int max_len = INT_MIN;
        int count = 0;
        while(j<nums.size()){
            if(nums[j]==0) count++;
            if(count>1){
                if(max_len<(j-i)) max_len = j-i-1;
                while(nums[i]!=0) i++;
                i++;
                count--;
            }
            j++;
        }
        if(count<=1){
            if(max_len<j-i) max_len = j-i-1;
        }
        if(max_len==INT_MIN) return 0;
        return max_len;
    }
};