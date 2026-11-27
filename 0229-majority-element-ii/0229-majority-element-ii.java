class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> list = new ArrayList<>();
        int count1 = 0;
        int ele1 = Integer.MIN_VALUE;
        int count2 = 0;
        int ele2 = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            if(count1==0 && ele2!=nums[i]){
                ele1 = nums[i];
                count1++;
            }
            else if(count2==0 && ele1!=nums[i]){
                ele2 = nums[i];
                count2++;
            }
            else if(ele1==nums[i]) count1++;
            else if(ele2==nums[i]) count2++;
            else{
                count1--;
                count2--;
            }
        }
        int count3 = 0;
        int count4 = 0;
        for(int i=0;i<nums.length;i++){
            if(ele1==nums[i]) count3++;
            if(ele2==nums[i]) count4++;
        }
        if(count3>nums.length/3) list.add(ele1);
        if(count4>nums.length/3) list.add(ele2);
        return list;
    }
}