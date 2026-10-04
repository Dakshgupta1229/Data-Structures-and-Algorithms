class Solution {
    public int minStartValue(int[] nums) {
        for(int i=1;i<nums.length;i++){
            nums[i] = nums[i] + nums[i-1];
        }
        int min_ele = Integer.MAX_VALUE;
        for(int i=0;i<nums.length;i++){
            if(min_ele>nums[i] && nums[i]<0){
                min_ele = nums[i];
            }
        }
        if(min_ele==Integer.MAX_VALUE) return 1;
        return Math.abs(min_ele) + 1;
    }
}