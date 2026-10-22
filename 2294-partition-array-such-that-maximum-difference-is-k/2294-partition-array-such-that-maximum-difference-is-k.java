class Solution {
    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        int min_value = nums[0];
        int max_value = nums[0];
        int count = 0;
        for(int i=0;i<nums.length;i++){
            max_value = nums[i];
            int diff = max_value - min_value;
            if(diff>k){
                count++;
                min_value = nums[i];
                max_value = nums[i];
            }
        }
        return count + 1;
    }
}