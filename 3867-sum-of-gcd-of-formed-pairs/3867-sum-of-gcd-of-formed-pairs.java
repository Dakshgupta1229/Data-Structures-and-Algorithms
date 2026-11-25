class Solution {

    int gcd(int num1,int num2){
        while(num1>0 && num2>0){
            if(num1>=num2) num1 = num1%num2;
            else num2 = num2%num1;
        }
        if(num1!=0) return num1;
        return num2;
    }

    public long gcdSum(int[] nums) {
        int[] prefix = new int[nums.length];
        int max_val = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            max_val = Math.max(max_val,nums[i]);
            prefix[i] = gcd(nums[i],max_val);
        }
        Arrays.sort(prefix);
        long sum = 0;
        int i=0;
        int j=nums.length-1;
        while(i<j){
            sum = sum + (long)gcd(prefix[i],prefix[j]);
            i++;
            j--;
        }
        return sum;
    }
}