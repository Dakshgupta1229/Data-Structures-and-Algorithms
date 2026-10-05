class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_len = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) count++;
            else{
                if(max_len<count) max_len = count;
                count = 0;
            }
        }
        if(max_len<count) max_len = count;
        return max_len;
    }
};