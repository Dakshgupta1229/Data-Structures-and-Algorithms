class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int count_one = 0;
        int max_ele = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==1) count_one++;
            else{
                if(max_ele<count_one) max_ele = count_one;
                count_one = 0;
            }
        }
        if(max_ele<count_one) max_ele = count_one;
        return max_ele;
    }
}