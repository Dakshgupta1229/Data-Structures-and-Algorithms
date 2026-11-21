class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length==0) return 0;
        Arrays.sort(nums);
        int max_length = 1;
        int count = 0;
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            if(list.size()==0) list.add(nums[i]);
            else if(list.get(list.size()-1)!=nums[i]) list.add(nums[i]);
        }
        for(int i=1;i<list.size();i++){
            if(list.get(i)-list.get(i-1)==1){
                count++;
            }
            else{
                if(max_length<count+1) max_length = count+1;
                count = 0;
            }
        }
        if(max_length<count+1) max_length = count + 1;
        return max_length;
    }
}