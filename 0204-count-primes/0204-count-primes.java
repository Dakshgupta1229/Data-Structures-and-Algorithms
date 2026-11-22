class Solution {
    public int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        int[] sieve = new int[n+1];
        Arrays.fill(sieve,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=Math.sqrt(n);i++){
            for(int j=i*i;j<=n;j+=i){
                sieve[j] = 0;
            }
        }
        int count = 0;
        for(int i=2;i<sieve.length;i++){
            if(sieve[i]==1 && i<n) count++;
        }
        return count;
    }
}