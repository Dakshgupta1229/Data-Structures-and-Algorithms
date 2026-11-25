class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int middle_ele = -1;
        if(nums.length%2==0) middle_ele = nums[nums.length/2 - 1];
        else middle_ele = nums[nums.length/2];
        int sum = 0;
        for(int i=0;i<nums.length;i++){
            sum = sum + Math.abs(nums[i] - middle_ele);
        }
        return sum;
    }
}