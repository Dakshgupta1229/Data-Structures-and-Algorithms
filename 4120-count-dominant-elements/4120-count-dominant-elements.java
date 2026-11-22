class Solution {
    public int countDominantElements(int[] nums) {
        if(nums.length==1) return 1;
        int count = 0;
        for(int i=0;i<nums.length;i++){
            if(i==0){
                if(nums[i]>=nums[i+1]) count++;
            }
            else if(i==nums.length-1){
                if(nums[i]>=nums[i-1]) count++;
            }
            else{
                double average = ((double)(nums[i-1]) + (double)(nums[i+1]))/(double)(2);
                if((double)nums[i]>=(average)) count++;
            }
        }
        return count;
    }
}