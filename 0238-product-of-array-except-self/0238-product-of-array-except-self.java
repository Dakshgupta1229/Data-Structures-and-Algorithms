class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] prefix = new int[nums.length];
        int[] suffix = new int[nums.length];
        prefix[0] = 1;
        suffix[nums.length-1] = 1;
        int product = nums[0];
        for(int i=1;i<nums.length;i++){
            prefix[i] = product;
            product = product * nums[i];
        }
        product = nums[nums.length-1];
        for(int i=nums.length-2;i>=0;i--){
            suffix[i] = product;
            product = product * nums[i];
        }
        for(int i=0;i<nums.length;i++){
            nums[i] = prefix[i] * suffix[i];
        }
        return nums;
    }
}