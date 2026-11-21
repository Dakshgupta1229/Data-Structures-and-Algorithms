class Solution {
    public int minimumDifference(int[] nums, int k) {
        int min_ele = Integer.MAX_VALUE;
        Arrays.sort(nums);
        if(min_ele>(nums[k-1] - nums[0])) min_ele = nums[k-1] - nums[0];
        for(int i=1;i<=nums.length-k;i++){
            int diff = nums[i+k-1] - nums[i];
            if(min_ele>diff) min_ele = diff;
        }
        return min_ele;
    }
}