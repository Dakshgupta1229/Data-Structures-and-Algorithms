class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int count = 0;
        int max_len = INT_MIN;
        while(j<nums.size()){
            if(nums[j]==0) count++;
            if(count>k){
                if(max_len<j-i) max_len = j-i;
                while(nums[i]!=0) i++;
                i++;
                count--;
            }
            j++;
        }
        if(count<=k){
            if(max_len<j-i) max_len = j-i;
        }
        if(max_len==INT_MIN) return 0;
        return max_len;
    }
};