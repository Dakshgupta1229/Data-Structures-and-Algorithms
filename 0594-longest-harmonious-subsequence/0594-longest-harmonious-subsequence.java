class Solution {
    public int findLHS(int[] nums) {
        Arrays.sort(nums);
        Map<Integer,List<Integer>> map = new TreeMap<>();
        for(int i=0;i<nums.length;i++){
            map.computeIfAbsent(nums[i],k -> new ArrayList<>()).add(i);
        }
        int ele = Integer.MIN_VALUE;
        int max_length = 0;
        for(Integer p:map.keySet()){
            if(ele==Integer.MIN_VALUE){
                ele = p;
            }
            else{
                if((p-ele)==1){
                    System.out.println(p+" "+ele);
                    List<Integer> list1 = map.get(p);
                    List<Integer> list2 = map.get(ele);
                    if(max_length<list1.get(list1.size()-1)-list2.get(0)+1){
                        max_length = list1.get(list1.size()-1) - list2.get(0) + 1;
                    }
                }
                ele = p;
            }
        }
        return max_length;


    }
}