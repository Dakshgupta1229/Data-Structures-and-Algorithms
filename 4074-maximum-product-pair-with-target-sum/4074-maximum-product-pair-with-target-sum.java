class Solution {
    public int[] maxProductPair(int[] nums, int target) {
        int first = -1;
        int second = -1;
        int max_product = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            for(int j=0;j<nums.length;j++){
                int sum = nums[i] + nums[j];
                int p = nums[i] * nums[j];
                if(sum==target){
                    if(max_product<p && nums[i]>nums[j] && i!=j){
                        first = i;
                        second = j;
                        max_product = p;
                    }
                }
            }
        }
        if(first==-1) return new int[]{-1,-1};
        return new int[]{first,second};
    }
}