class Solution {

    void generate(int n,String str,List<String> list){
        if(str.length()==n){
            list.add(str);
            return;
        }
        generate(n,str+'1',list);
        generate(n,str+'0',list);
    }

    public String findDifferentBinaryString(String[] nums) {
        List<String> list = new ArrayList<>();
        generate(nums.length,"",list);
        Set<String> set = new HashSet<>();
        for(int i=0;i<nums.length;i++) set.add(nums[i]);
        for(int i=0;i<list.size();i++){
            if(!set.contains(list.get(i))) return list.get(i);
        }
        return "";
        
    }
}