class Solution {
    public int missingNumber(int[] nums) {
        int i=0;
        while(i<nums.length){
            int ele = nums[i];
            if(ele==i) i++;
            else if(ele>=nums.length) i++;
            else{
                int temp = nums[i];
                nums[i] = nums[ele];
                nums[ele] = temp;
            }
        }
        for(i=0;i<nums.length;i++){
            if(nums[i]!=i) return i;
        }
        return nums.length;
    }
}