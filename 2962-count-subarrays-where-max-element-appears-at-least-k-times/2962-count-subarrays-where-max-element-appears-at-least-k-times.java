class Solution {
    public long countSubarrays(int[] nums, int k) {
        int max_ele = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            if(max_ele<nums[i]) max_ele = nums[i];
        }
        long sum = 0;
        int count = 0;
        int i=0;
        int j=0;
        while(j<nums.length){
            if(nums[j]==max_ele) count++;
            while(count>=k && i<nums.length){
                sum = sum + (long)(nums.length - j);
                if(nums[i]==max_ele) count--;
                i++;
            }
            j++;
        }
        return sum;
    }
}