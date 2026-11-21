class Solution {
    public int minStartValue(int[] nums) {
        for(int i=1;i<nums.length;i++){
            nums[i] = nums[i] + nums[i-1];
        }
        int min_value = Integer.MAX_VALUE;
        for(int i=0;i<nums.length;i++){
            if(min_value>nums[i]){
                min_value = nums[i];
            }
        }
        if(min_value<0) return Math.abs(min_value) + 1;
        return 1;
    }
}