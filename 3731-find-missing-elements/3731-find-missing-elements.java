class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        List<Integer> list = new ArrayList<>();
        int min_ele = Integer.MAX_VALUE;
        int max_ele = Integer.MIN_VALUE;
        Set<Integer> set = new HashSet<>();
        for(int i=0;i<nums.length;i++){
            if(min_ele>nums[i]) min_ele = nums[i];
            if(max_ele<nums[i]) max_ele = nums[i];
            set.add(nums[i]);
        }

        for(int i=min_ele;i<=max_ele;i++){
            if(!set.contains(i)) list.add(i);
        }
        return list;
    }
}