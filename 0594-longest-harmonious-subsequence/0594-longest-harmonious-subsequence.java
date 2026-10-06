class Solution {
    public int findLHS(int[] nums) {
        Arrays.sort(nums);
        TreeMap<Integer,List<Integer>> map = new TreeMap<>();
        for(int i=0;i<nums.length;i++){
            map.putIfAbsent(nums[i],new ArrayList<>());
            map.get(nums[i]).add(i);
        }
        int num1 = Integer.MIN_VALUE;
        int ele1 = Integer.MIN_VALUE;
        int max_len = 0;
        for(Map.Entry<Integer,List<Integer>> entry:map.entrySet()){
            int value = entry.getKey();
            List<Integer> list = entry.getValue();
            if(ele1==Integer.MIN_VALUE){
                ele1 = list.get(0);
                num1 = value;
            }
            else{
                int ele2 = list.get(list.size()-1);
                int num2 = value;
                if(num2-num1==1 && max_len<ele2-ele1+1){
                    max_len = ele2 - ele1 + 1;
                }
                ele1 = list.get(0);
                num1 = value;
            }
        }
        return max_len;
    }
}