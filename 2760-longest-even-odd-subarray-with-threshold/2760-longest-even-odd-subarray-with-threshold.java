class Solution {
    public int longestAlternatingSubarray(int[] nums, int threshold) {
        int max_length = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]%2==0 && nums[i]<=threshold){
                if(max_length<1) max_length = 1;
                int count = 1;
                for(int j=i;j<nums.length-1;j++){
                    if(nums[j]%2!=nums[j+1]%2 && nums[j]<=threshold && nums[j+1]<=threshold){
                        count++;
                    }
                    else break;
                }
                if(max_length<count && count!=1) max_length = count;
            }
        }
        return max_length;
    }
}