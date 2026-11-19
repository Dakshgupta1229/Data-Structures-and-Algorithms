class Solution {
    public int findGCD(int[] nums) {
        int min_ele = Integer.MAX_VALUE;
        int max_ele = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            if(min_ele>nums[i]) min_ele = nums[i];
            if(max_ele<nums[i]) max_ele = nums[i];
        }
        while(min_ele>0 && max_ele>0){
            if(min_ele>max_ele) min_ele = min_ele % max_ele;
            else max_ele = max_ele % min_ele;
        }
        if(min_ele!=0) return min_ele;
        return max_ele;
    }
}