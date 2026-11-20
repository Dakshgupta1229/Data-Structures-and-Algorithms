class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new ArrayList<>();
        int i=0;
        while(i<nums.length){
            int ele = nums[i];
            if(ele==(i+1)) i++;
            else if(nums[ele-1]==ele) i++;
            else if(ele>nums.length) i++;
            else{
                int temp = nums[i];
                nums[i] = nums[ele-1];
                nums[ele-1] = temp;
            }
        }
        for(i=0;i<nums.length;i++){
            if(nums[i]!=(i+1)) list.add(i+1);
        }
        return list;
    }
}