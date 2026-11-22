class Solution {

    long factorial(long num){
        long fact = 1;
        for(int i=2;i<=num;i++){
            fact = (fact%1000000007 * i%1000000007)%1000000007;
        }
        return fact%1000000007;
    }

    public int numPrimeArrangements(int n) {
        int[] sieve = new int[n+1];
        Arrays.fill(sieve,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=Math.sqrt(n);i++){
            for(int j=i*i;j<sieve.length;j+=i){
                sieve[j] = 0;
            }
        }
        long count1 = 0;
        for(int i=0;i<sieve.length;i++){
            if(sieve[i]==1) count1++;
        }
        long count2 = n - count1;
        long result = factorial((long)count1)%1000000007 * factorial((long)count2)%1000000007;
        return (int)result;
    }
}