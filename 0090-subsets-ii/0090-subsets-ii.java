class Solution {

    void subset(int[] nums,int index,List<Integer> list2,List<List<Integer>> list){
        if(index>=nums.length){
            list.add(new ArrayList<>(list2));
            return;
        }
        list2.add(nums[index]);
        subset(nums,index+1,list2,list);
        list2.remove(list2.size()-1);
        if(list2.size()==0 || (list2.size()>0 && list2.get(list2.size()-1)!=nums[index])){
            subset(nums,index+1,list2,list);
        }
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> list = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        subset(nums,0,list2,list);
        return list;
    }
}