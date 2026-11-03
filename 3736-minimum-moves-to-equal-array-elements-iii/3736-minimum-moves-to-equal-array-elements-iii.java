class Solution {
    public int minMoves(int[] nums) {
        int max_ele = Integer.MIN_VALUE;
        int sum = 0;
        for(int i=0;i<nums.length;i++){
            if(max_ele<nums[i]) max_ele = nums[i];
        }
        for(int i=0;i<nums.length;i++){
            sum = sum + (max_ele - nums[i]);
        }
        return sum;
    }
}