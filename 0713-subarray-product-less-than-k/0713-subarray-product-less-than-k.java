class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int i=0;
        int j=0;
        long product = 1;
        int sum = 0;
        if(k<=1) return 0;
        while(j<nums.length){
            product = product * nums[j];
            while(product>=k && i<nums.length){
                product = product/nums[i];
                sum = sum + (j-i);
                i++;
            }
            j++;
        }
        while(i<nums.length){
                sum = sum + (nums.length - i);
                product = product/nums[i];
            i++;
        }
        if(sum<0) return 0;
        return sum;

    }
}