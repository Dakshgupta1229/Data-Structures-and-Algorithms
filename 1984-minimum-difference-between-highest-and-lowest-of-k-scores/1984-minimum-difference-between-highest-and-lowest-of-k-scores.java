class Solution {
    public int minimumDifference(int[] nums, int k) {
        Arrays.sort(nums);
        int result = Integer.MAX_VALUE;
        for(int i=0;i<=nums.length-k;i++){
            int max_ele = Integer.MIN_VALUE;
            int min_ele = Integer.MAX_VALUE;
            for(int j=i;j<i+k;j++){
                if(max_ele<nums[j]) max_ele = nums[j];
                if(min_ele>nums[j]) min_ele = nums[j];
            }
            int diff = max_ele - min_ele;
            if(result>diff) result = diff;
        }
        return result;
    }
}