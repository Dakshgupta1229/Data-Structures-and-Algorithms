class Solution {

    void traverse(String str,Set<String> set,int n,String[] result){
        if(str.length()>n) return;
        if(str.length()==n){
            if(!set.contains(str)){
                result[0] = str;
                return;
            }
        }
        if(!(result[0].equals(""))) return;
        traverse(str+'1',set,n,result);
        traverse(str+'0',set,n,result);
    }

    public String findDifferentBinaryString(String[] nums) {
        String[] result = {""};
        Set<String> set = new HashSet<>();
        for(int i=0;i<nums.length;i++){
            set.add(nums[i]);
        }
        String str = "";
        traverse(str,set,nums.length,result);
        return result[0];
    }
}