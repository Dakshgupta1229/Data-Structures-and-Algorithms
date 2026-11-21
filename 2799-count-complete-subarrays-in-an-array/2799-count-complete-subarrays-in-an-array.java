class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for(int i=0;i<nums.length;i++) set.add(nums[i]);
        int n = set.size();
        int i=0;
        int j=0;
        Map<Integer,Integer> map = new HashMap<>();
        int count = 0;
        while(j<nums.length){
            if(!map.containsKey(nums[j])) map.put(nums[j],1);
            else map.put(nums[j],map.get(nums[j])+1);
            while(map.size()==n){
                count = count + (nums.length - j);
                if(map.containsKey(nums[i])){
                    int freq = map.get(nums[i]);
                    if(freq==1) map.remove(nums[i]);
                    else map.put(nums[i],freq-1);
                    i++;
                }
            }
            j++;
        }
        return count;
    }
}