class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int i=0;
        int j=0;
        int sum = 0;
        int min_length = Integer.MAX_VALUE;
        while(i<nums.length){
            sum = sum + nums[i];
            while(sum>=target){
                if(min_length>(i-j+1)) min_length = i-j+1;
                sum = sum - nums[j];
                j++;
            }
            i++;
        }
        if(min_length==Integer.MAX_VALUE) return 0;
        return min_length;
    }
}