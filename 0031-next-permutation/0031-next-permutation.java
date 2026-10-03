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
            int i=0;
            int j=nums.length-1;
            while(i<j){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
            return;
        }
        else{
            int i=pivot_idx+1;
            int j=nums.length-1;
            while(i<j){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
            for(i=pivot_idx+1;i<nums.length;i++){
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