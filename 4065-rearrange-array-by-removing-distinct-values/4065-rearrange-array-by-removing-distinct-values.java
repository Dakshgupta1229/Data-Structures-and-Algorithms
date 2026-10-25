class Solution {
    public int[] rearrangeArray(int[] nums) {
        int[] arr = new int[nums.length];
        TreeMap<Integer,Integer> map = new TreeMap<>();
        for(int i=0;i<nums.length;i++){
            if(!map.containsKey(nums[i])){
                map.put(nums[i],1);
            }
            else{
                map.put(nums[i],map.get(nums[i])+1);
            }
        }
        int index = 0;
        while(map.size()>0){
            if(map.size()==0) break;
            List<Integer> list = new ArrayList<>();
            for(Integer p:map.keySet()){
                int ele = p;
                int freq = map.get(ele);
                arr[index] = ele;
                index++;
                freq--;
                map.put(ele,freq);
                if(freq==0) list.add(ele);
            }
            for(int i=0;i<list.size();i++){
                map.remove(list.get(i));
            }
        }
        return arr;
        
    }
}