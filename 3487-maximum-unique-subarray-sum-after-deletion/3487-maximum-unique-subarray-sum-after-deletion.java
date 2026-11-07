class Solution {
    public int maxSum(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int max_ele = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>0) set.add(nums[i]);
            if(max_ele<nums[i]) max_ele = nums[i];
        }
        if(set.size()==0) return max_ele;
        int sum = 0;
        for(Integer p:set){
            sum = sum + p;
        }
        return sum;
    }
}