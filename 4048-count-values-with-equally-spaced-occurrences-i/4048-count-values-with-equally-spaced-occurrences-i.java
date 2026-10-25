class Solution {
    public int countSpecialIntegers(int[] nums) {
        Map<Integer,ArrayList<Integer>> map = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            map.computeIfAbsent(nums[i],k -> new ArrayList<>()).add(i);
        }
        int count = 0;
        for(Integer p:map.keySet()){
            int ele = p;
            ArrayList<Integer> list = map.get(ele);
            if(list.size()==3){
                int space = list.get(1) - list.get(0);
                boolean flag = true;
                for(int i=1;i<list.size();i++){
                    if(list.get(i)-list.get(i-1)!=space){
                        flag = false;
                        break;
                    }
                }
                if(flag==true) count++;
            }
        }
        return count;
    }
}