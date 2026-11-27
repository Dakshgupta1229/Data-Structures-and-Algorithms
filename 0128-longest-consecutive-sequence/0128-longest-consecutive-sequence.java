class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length==0) return 0;
        Set<Integer> set = new HashSet<>();
        for(int i=0;i<nums.length;i++) set.add(nums[i]);
        int max_length = 1;
        for(Integer p:set){
            int ele = p;
            if(set.contains(ele-1)) continue;
            else{
                int ele2 = ele;
                int count = 0;
                while(set.contains(ele2)){
                    ele2++;
                    count++;
                }
                if(max_length<count) max_length = count;
            }
        }
        return max_length;
    }
}