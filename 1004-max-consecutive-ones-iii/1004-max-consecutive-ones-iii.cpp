class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int count = 0;
        int max_len = INT_MIN;
        while(j<nums.size()){
            if(nums[j]==0) count++;
            while(count>k && i<nums.size()){
                if(max_len<(j-i)) max_len = j-i;
                if(nums[i]==0){
                    count--;
                }
                i++;
            }
            j++;
        }
        if(max_len<(j-i)) max_len = j - i;
        return max_len;
    }
};