class Solution {
    public boolean canJump(int[] nums) {
        int max_len = 0;
        for(int i=0;i<nums.length;i++){
            if(i>max_len) return false;
            else{
                max_len = Math.max(max_len,i+nums[i]);
            }
        }
        return true;
    }
}