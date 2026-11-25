class Solution {
    public List<Integer> findLonely(int[] nums) {
        List<Integer> list = new ArrayList<>();
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(!map.containsKey(nums[i])) map.put(nums[i],1);
            else map.put(nums[i],map.get(nums[i])+1);
        }
        for(Integer p:map.keySet()){
            int freq = map.get(p);
            if(freq==1){
                if(!map.containsKey(p-1)){
                    if(!map.containsKey(p+1)){
                        list.add(p);
                    }
                }
            }
        }
        return list;
    }
}