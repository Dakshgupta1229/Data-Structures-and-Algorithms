class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        int[] result = new int[queries.length];
        Arrays.sort(nums);
        for(int i=1;i<nums.length;i++){
            nums[i] = nums[i] + nums[i-1];
        }
        for(int i=0;i<queries.length;i++){
            int ele = queries[i];
            int low = 0;
            int high = nums.length-1;
            int ans = 0;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]<=ele){
                    ans = mid+1;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            result[i] = ans;
        }
        return result;
    }
}