class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length==0) return 0;
        Set<Integer> set = new TreeSet<>();
        for(int i= 0;i<nums.length;i++){
            set.add(nums[i]);
        }
        int first = Integer.MIN_VALUE;
        int count = 1;
        int max_length = 0;
        for(Integer x:set){
            if(first==Integer.MIN_VALUE){
                first = x;
            }
            else if(x-first==1){
                count++;
                first = x;
            }
            else{
                if(max_length<count) max_length = count;
                first = x;
                count = 1;
            }
        }
        if(max_length<count) max_length = count;
        return max_length;
    }
}