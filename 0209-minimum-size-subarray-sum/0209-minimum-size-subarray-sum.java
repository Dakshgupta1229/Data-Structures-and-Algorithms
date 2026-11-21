class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int i=0;
        int j=0;
        int sum = 0;
        int min_length = Integer.MAX_VALUE;
        while(j<nums.length){
            sum = sum + nums[j];
            while(sum>=target){
                if(min_length>(j-i+1)){
                    min_length = j-i+1;
                }
                sum = sum - nums[i];
                i++;
            }
            j++;
        }
        if(sum>=target){
            if(min_length<j-i) min_length = j-i;
        }
        if(min_length==Integer.MAX_VALUE) return 0;
        return min_length;
    }
}