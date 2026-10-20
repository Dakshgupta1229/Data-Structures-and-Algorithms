class Solution {
    public int maximumPrimeDifference(int[] nums) {
        int[] sieve = new int[100+1];
        Arrays.fill(sieve,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=Math.sqrt(100);i++){
            for(int j=i*i;j<sieve.length;j+=i){
                sieve[j] = 0;
            }
        }
        int first = -1;
        int second = -1;
        for(int i=0;i<nums.length;i++){
            if(sieve[nums[i]]==1 && first==-1) first = i;
            if(sieve[nums[i]]==1) second = i;
        }
        return Math.abs(first-second);
    }
}