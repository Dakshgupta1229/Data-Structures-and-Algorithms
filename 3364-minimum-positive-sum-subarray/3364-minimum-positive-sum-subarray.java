class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int min_sum = Integer.MAX_VALUE;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            int count = 0;
            for(int j=i;j<nums.size();j++){
                sum = sum + nums.get(j);
                count++;
                if(count>=l && count<=r){
                    if(min_sum>sum && sum>0) min_sum = sum;
                }
                if(count>r) break;
            }
        }
        if(min_sum==(Integer.MAX_VALUE)) return -1;
        return min_sum;
    }
}