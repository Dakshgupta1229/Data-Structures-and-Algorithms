class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int low = 1;
        int high = 1000000;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int sum = 0;
            for(int i=0;i<nums.length;i++){
                double ele = (double)nums[i]/(double)mid;
                sum = sum + (int)Math.ceil(ele);
            }
            System.out.println(sum + " " + mid);
            if(sum<=threshold){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
}