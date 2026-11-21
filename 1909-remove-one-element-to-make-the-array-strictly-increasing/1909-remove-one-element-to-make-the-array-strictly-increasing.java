class Solution {
    public boolean canBeIncreasing(int[] nums) {
        for(int i=0;i<nums.length;i++){
            List<Integer> list = new ArrayList<>();
            boolean result = true;
            for(int j=0;j<nums.length;j++){
                if(j!=i) list.add(nums[j]);
            }
            for(int k=1;k<list.size();k++){
                if(list.get(k)<=list.get(k-1)){
                    result = false;
                    break;
                }
            }
            if(result==true){
                return true;
            }
        }
        return false;
    }
}