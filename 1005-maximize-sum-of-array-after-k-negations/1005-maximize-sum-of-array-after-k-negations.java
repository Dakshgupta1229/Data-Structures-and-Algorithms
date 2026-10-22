class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {
        Arrays.sort(nums);
        if(nums[0]>=0){
            int sum = 0;
            if(k%2!=0) nums[0] = -(nums[0]);
            for(int i=0;i<nums.length;i++){
                sum = sum + nums[i];
            }
            return sum;
        }
        for(int i=0;i<nums.length;i++){
            if(k==0) break;
            if(nums[i]<0) nums[i] = -(nums[i]);
            else break;
            k--;
        }
        Arrays.sort(nums);
        if(k%2!=0) nums[0] = -(nums[0]);
        int sum = 0;
        for(int i=0;i<nums.length;i++) sum = sum + nums[i];
        return sum;
    }
}