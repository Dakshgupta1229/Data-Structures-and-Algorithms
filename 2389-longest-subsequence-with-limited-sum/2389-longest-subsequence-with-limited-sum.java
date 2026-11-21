class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        Arrays.sort(nums);
        for(int i=1;i<nums.length;i++){
            nums[i] = nums[i] + nums[i-1];
        }
        int[] result = new int[queries.length];
        for(int i=0;i<queries.length;i++){
            int low = 0;
            int high = nums.length-1;
            int target = queries[i];
            int ans = 0;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]<=target){
                    ans = mid + 1;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            result[i] = ans;
        }
        return result;
    }
}