class Solution {
    public int scoreDifference(int[] nums) {
        int first = 0;
        int second = 0;
        int current = 0;
        for(int i=0;i<nums.length;i++){
            if((i+1)%6==0){
                if(current==0) current = 1;
                else current = 0;
            }
            if(nums[i]%2!=0){
                if(current==0) current = 1;
                else current = 0;
            }
            if(current==0) first = first + nums[i];
            else second = second + nums[i];
        }
        return first - second;
    }
}