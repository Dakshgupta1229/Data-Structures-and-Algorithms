class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = 0;
        int min_diff = Integer.MAX_VALUE;
        for(int i=0;i<nums.length;i++){
            int j=i+1;
            int k=nums.length-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(min_diff>Math.abs(sum-target)){
                    min_diff = Math.abs(sum - target);
                    result = sum;
                }
                if(sum==target){
                    return sum;
                }
                else if(sum<target){
                    j++;
                    while(j<nums.length && j>=0 && nums[j]==nums[j-1]) j++;
                }
                else{
                    k--;
                    while(k<nums.length && k>=0 && nums[k]==nums[k+1]) k--;
                }

            }
        }
        return result;
    }
}