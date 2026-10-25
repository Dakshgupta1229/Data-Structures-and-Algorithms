class Solution {
    public int minimumRightShifts(List<Integer> nums) {
        int i=0;
        int j=nums.size()-1;
        int count = 0;
        while(i<j){
            if(nums.get(i)>nums.get(j)){
                j--;
                count++;
            }
            else break;
        }
        List<Integer> list1 = new ArrayList<>();
        for(i=nums.size()-count;i<nums.size();i++){
            list1.add(nums.get(i));
        }
        for(i=0;i<nums.size()-count;i++){
            list1.add(nums.get(i));
        }
        Collections.sort(nums);
        if(list1.equals(nums)) return count;
        return -1;
    }
}