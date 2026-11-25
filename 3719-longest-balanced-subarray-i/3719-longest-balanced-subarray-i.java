class Solution {
    public int longestBalanced(int[] nums) {
        int max_length = 0;
        for(int i=0;i<nums.length;i++){
            Set<Integer> set1 = new HashSet<>();
            Set<Integer> set2 = new HashSet<>();
            for(int j=i;j<nums.length;j++){
                if(nums[j]%2==0) set1.add(nums[j]);
                else set2.add(nums[j]);
                int n1 = set1.size();
                int n2 = set2.size();
                if(n1==n2){
                    if(max_length<(j-i+1)) max_length = j-i+1;
                }
            }
            if(set1.size()==set2.size()){
                if(max_length<(nums.length-i)) max_length = nums.length - i;
            }
        }
        return max_length;
    }
}