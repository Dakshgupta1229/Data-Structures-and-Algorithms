class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        vector<int> sieve(n+1,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=sqrt(n);i++){
            for(int j=i*i;j<=n;j+=i){
                sieve[j] = 0;
            }
        }
        int count = 0;
        for(int i=0;i<sieve.size();i++){
            if(sieve[i]==1 && i<n) count++;
        }
        return count;
    }
};