class Solution {
    public long maxAlternatingSum(int[] nums) {
        for(int i=0;i<nums.length;i++){
            nums[i] = Math.abs(nums[i]);
        }
        Arrays.sort(nums);
        long sum = 0;
        int i=0;
        int j=nums.length-1;
        while(i<j){
            sum = sum - (long)Math.pow(nums[i],2);
            sum = sum + (long)Math.pow(nums[j],2);
            i++;
            j--;
        }
        if(i==j) sum = sum + (long)Math.pow(nums[i],2);
        return sum;
    }
}