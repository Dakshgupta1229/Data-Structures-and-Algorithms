class Solution {
    public long splitArray(int[] nums) {
        long[] sieve = new long[nums.length+1];
        Arrays.fill(sieve,(long)1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=Math.sqrt(nums.length);i++){
            for(int j=i*i;j<sieve.length;j+=i){
                sieve[j] = (long)0;
            }
        }
        long sum1 = 0;
        long sum2 = 0;
        for(int i=0;i<nums.length;i++){
            if(sieve[i]==1) sum1 = sum1 + (long)nums[i];
            else sum2 = sum2 + (long)nums[i];
        }
        return (long)Math.abs(sum1 - sum2);
    }
}