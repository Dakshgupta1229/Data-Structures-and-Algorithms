class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0;i<nums.length;i++){
            while(i>0 && i<nums.length && nums[i]==nums[i-1]) i++;
            for(int j=i+1;j<nums.length;j++){
                while(j>i+1 && j<nums.length && nums[j]==nums[j-1]) j++;
                int k = j+1;
                int l = nums.length-1;
                while(k<l){
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[k] + (long)nums[l];
                    if(sum==(long)target){
                        List<Integer> list2 = new ArrayList<>();
                        list2.add(nums[i]);
                        list2.add(nums[j]);
                        list2.add(nums[k]);
                        list2.add(nums[l]);
                        list.add(list2);
                        k++;
                        l--;
                        while(k>=0 && k<nums.length && nums[k]==nums[k-1]) k++;
                        while(l>=0 && l<nums.length && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum<(long)target){
                        k++;
                        while(k>=0 && k<nums.length && nums[k]==nums[k-1]) k++;
                    }
                    else{
                        l--;
                        while(l>=0 && l<nums.length && nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }
        return list;
    }
}