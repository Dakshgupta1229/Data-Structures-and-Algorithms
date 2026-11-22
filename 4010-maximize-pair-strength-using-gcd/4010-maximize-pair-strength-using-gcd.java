class Solution {

    long find(long num1,long num2){
        while(num1>0 && num2>0){
            if(num1>num2) num1 = num1%num2;
            else num2 = num2%num1;
        }
        if(num1!=0) return num1;
        return num2;
    }

    public long maxPairStrength(int[] nums) {
        long max_strength = 0;
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                long product = (long)nums[i] * (long)nums[j];
                long gcd = (long)Math.pow(find((long)nums[i],(long)nums[j]),2);
                if(max_strength<(product/gcd)) max_strength = product/gcd;
            }
        }
        return max_strength;
    }
}