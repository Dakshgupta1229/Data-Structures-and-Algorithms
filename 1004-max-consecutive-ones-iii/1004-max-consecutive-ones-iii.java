class Solution {
    public int longestOnes(int[] nums, int k) {
        int i=0;
        int j=0;
        int count = 0;
        int max_len = Integer.MIN_VALUE;
        while(j<nums.length){
            if(nums[j]==0) count++;
            if(count>k){
                if(max_len<(j-i)) max_len = j-i;
                while(nums[i]!=0) i++;
                i++;
                count--;
            }
            j++;
        }
        if(count<=k){
            if(max_len<j-i) max_len = j-i;
        }
        if(max_len==Integer.MIN_VALUE) return 0;
        return max_len;

    }
}