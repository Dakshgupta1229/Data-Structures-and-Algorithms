class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        List<Integer> list = new ArrayList<>();
        Arrays.sort(nums);
        int sum = 0;
        for(int i=0;i<nums.length;i++) sum = sum + nums[i];
        int sum2 = 0;
        for(int i=nums.length-1;i>=0;i--){
            list.add(nums[i]);
            sum = sum - nums[i];
            sum2 = sum2 + nums[i];
            if(sum2>sum) break;
        }
        return list;
    }
}