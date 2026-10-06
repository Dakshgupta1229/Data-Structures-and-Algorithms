class Solution {
    public int countCompleteSubarrays(int[] nums) {
        int count = 0;
        Set<Integer> set = new HashSet<>();
        for(int i=0;i<nums.length;i++){
            set.add(nums[i]);
        }
        int n = set.size();
        for(int i=0;i<nums.length;i++){
            Set<Integer> set1 = new HashSet<>();
            int idx = -1;
            for(int j=i;j<nums.length;j++){
                set1.add(nums[j]);
                int n1 = set1.size();
                if(n1==n){
                    idx = j;
                    break;
                }
            }
            if(idx==-1) break;
            count = count + nums.length - idx;
        }
        return count;
    }
}