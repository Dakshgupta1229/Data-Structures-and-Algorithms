class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if(k<=1) return 0;
        int i=0;
        int j=0;
        long product = 1;
        int count = 0;
        while(j<nums.length){
            product = product * nums[j];
            while(product>=k && i<nums.length){
                count = count + (j-i);
                product = product/nums[i];
                i++;
            }
            j++;
        }
        while(i<nums.length){
            count = count + (j-i);
            product = product/nums[i];
            i++;
        }
        return count;
    }
}