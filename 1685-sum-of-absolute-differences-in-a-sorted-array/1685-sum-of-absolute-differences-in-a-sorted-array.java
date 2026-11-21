class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int[] prefix = new int[nums.length];
        int[] suffix = new int[nums.length];
        prefix[0] = 0;
        for(int i=0;i<nums.length-1;i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        suffix[suffix.length-1] = 0;
        for(int i=suffix.length-1;i>=1;i--){
            suffix[i-1] = suffix[i] + nums[i];
        }
        int[] result = new int[nums.length];
        for(int i=0;i<nums.length;i++){
            int left_sum = (i*nums[i]) - prefix[i];
            int right_sum = suffix[i] - ((nums.length-i-1) * nums[i]);
            result[i] = left_sum + right_sum;
        }
        return result;
    }
}