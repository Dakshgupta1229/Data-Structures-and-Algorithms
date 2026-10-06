class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0,1);
        int sum = 0;
        int count = 0;
        for(int i=0;i<nums.length;i++){
            sum = sum + nums[i];
            int rem = sum - k;
            if(map.containsKey(rem)){
                count = count + map.get(rem);
            }
            if(map.containsKey(sum)){
                map.put(sum,map.get(sum)+1);
            }
            else map.put(sum,1);
        }
        return count;
    }
}