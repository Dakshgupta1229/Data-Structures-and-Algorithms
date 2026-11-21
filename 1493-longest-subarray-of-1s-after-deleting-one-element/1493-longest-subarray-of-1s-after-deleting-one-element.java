class Solution {
    public int longestSubarray(int[] nums) {
        int i=0;
        int j=0;
        int max_length = 0;
        int count_zero = 0;
        while(j<nums.length){
            if(nums[j]==0) count_zero++;
            if(count_zero>1){
                if(max_length<(j-i)) max_length = j-i-1;
                while(i<nums.length && nums[i]!=0) i++;
                i++;
                count_zero--;
            }
            j++;
        }
        if(max_length<(j-i)) max_length = j-i-1;
        return max_length;
    }
}