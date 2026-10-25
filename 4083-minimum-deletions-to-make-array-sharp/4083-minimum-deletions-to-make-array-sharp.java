class Solution {
    public int minDeletions(int[] nums) {
        int ele = nums[0];
        int count = 1;
        int result = 0;
        for(int i=1;i<nums.length;i++){
            if(ele==nums[i]){
                count++;
            }
            else{
                ele = nums[i];
                count = 1;
            }
            if(count>1) result++;
        }
        return result;
    }
}