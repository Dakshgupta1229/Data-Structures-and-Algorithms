class Solution {
    public int[] rearrangeArray(int[] nums) {
        int[] arr = new int[nums.length];
        int i1 = 0;
        int j1 = 1;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>=0){
                arr[i1] = nums[i];
                i1+=2;
            }
            else{
                arr[j1] = nums[i];
                j1+=2;
            }
        }
        return arr;
    }
}