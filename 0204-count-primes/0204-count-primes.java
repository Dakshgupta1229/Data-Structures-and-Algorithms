class Solution {
    public int countPrimes(int n) {
        if(n<=2) return 0;
        int[] sieve = new int[n];
        Arrays.fill(sieve,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=Math.sqrt(n);i++){
            for(int j=i*i;j<sieve.length;j+=i){
                sieve[j] = 0;
            }
        }
        int count = 0;
        for(int i=0;i<sieve.length;i++){
            if(sieve[i]==1) count++;
        }
        return count;
    }
}