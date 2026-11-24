class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            int sum = 0;
            for(int j=i;j<nums.length;j++){
                sum = sum + nums[j]%1000000007;
                list.add(sum);
            }
        }
        Collections.sort(list);
        int sum = 0;
        for(int i=left-1;i<right;i++){
            sum = (sum + list.get(i))%1000000007;
        }
        return sum%1000000007;
    }
}