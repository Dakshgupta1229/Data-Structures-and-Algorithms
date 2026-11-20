class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] prefix = new int[nums.length];
        int product = 1;
        prefix[0] = product;
        for(int i=1;i<nums.length;i++){
            product = product * nums[i-1];
            prefix[i] = product;
        }
        int product2 = 1;
        int[] suffix = new int[nums.length];
        suffix[suffix.length-1] = product2;
        for(int i=nums.length-2;i>=0;i--){
            product2 = product2 * nums[i+1];
            suffix[i] = product2;
        }
        for(int i=0;i<nums.length;i++){
            nums[i] = prefix[i] * suffix[i];
        }
        return nums;

    }
}