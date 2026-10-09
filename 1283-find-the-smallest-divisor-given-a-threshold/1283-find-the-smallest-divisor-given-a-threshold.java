class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int low = 1;
        int high = 1000000;
        int idx = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int sum = 0;
            for(int i=0;i<nums.length;i++){
                float ele = (float)nums[i]/(float)mid;
                int n = (int)(Math.ceil(ele));
                sum = sum + n;
            }
            if(sum<=threshold){
                idx = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return idx;
    }
}