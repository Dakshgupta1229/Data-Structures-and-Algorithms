class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> list = new ArrayList<>();
        for(int i=0;i<l.length;i++){
            int index1 = l[i];
            int index2 = r[i];
            List<Integer> list2 = new ArrayList<>();
            for(int j=index1;j<=index2;j++){
                list2.add(nums[j]);
            }
            boolean flag = true;
            Collections.sort(list2);
            if(list2.size()>1){
                int diff = list2.get(1) - list2.get(0);
                for(int k=1;k<list2.size();k++){
                    int ele1 = list2.get(k);
                    int ele2 = list2.get(k-1);
                    if(ele1-ele2!=diff){
                        flag = false;
                        break;
                    }
                }
            }
            list.add(flag);
        }
        return list;
    }
}