class Solution {
    public int longestOnes(int[] nums, int k) {
        int count_zero = 0;
        int i=0;
        int j=0;
        int max_length = 0;
        while(j<nums.length){
            if(nums[j]==0) count_zero++;
            if(count_zero>k){
                if(max_length<j-i) max_length = j-i;
                while(i<nums.length && nums[i]!=0) i++;
                i++;
                count_zero--;
            }
            j++;
        }
        if(max_length<j-i) max_length = j-i;
        return max_length;
    }
}