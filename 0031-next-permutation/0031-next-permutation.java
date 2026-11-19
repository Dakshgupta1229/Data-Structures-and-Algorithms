class Solution {
    public void nextPermutation(int[] nums) {
        int pivot_idx = -1;
        for(int i=nums.length-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot_idx = i;
                break;
            }
        }
        if(pivot_idx==-1){
            Arrays.sort(nums);
        }
        else{
            int i1=pivot_idx+1;
            int j1=nums.length-1;
            while(i1<j1){
                int temp = nums[i1];
                nums[i1] = nums[j1];
                nums[j1] = temp;
                i1++;
                j1--;
            }
            for(int i=pivot_idx+1;i<nums.length;i++){
                if(nums[i]>nums[pivot_idx]){
                    int temp = nums[i];
                    nums[i] = nums[pivot_idx];
                    nums[pivot_idx] = temp;
                    break;
                }
            }
        }
    }
}