class Solution {
    public int countSpecialIntegers(int[] nums) {
        Map<Integer,List<Integer>> map = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            map.computeIfAbsent(nums[i],k-> new ArrayList<>()).add(i);
        }
        int count = 0;
        for(Integer p:map.keySet()){
            List<Integer> list = map.get(p);
            int ele = list.get(0);
            boolean flag = true;
            for(int i=1;i<list.size();i++){
                int ele2 = list.get(i);
                if(ele2-ele==1){
                    ele = ele2;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag==true) count++;
        }

        return count;
    }
}