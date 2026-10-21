class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_length = 0;
        int i=0;
        int j=0;
        int count = 0;
        while(i<nums.size()){
            if(nums[i]==0) count++;
            if(count>k){
                if(max_length<(i-j)) max_length = i-j;
                while(nums[j]!=0 && j<nums.size()) j++;
                count--;
                j++;
            }
            i++;
        }
        if(max_length<(i-j)) max_length = i-j;
        return max_length;
    }
};