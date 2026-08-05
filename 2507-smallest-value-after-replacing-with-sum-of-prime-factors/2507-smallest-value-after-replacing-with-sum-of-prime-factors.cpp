class Solution {
public:
    int smallestValue(int n) {
        vector<int> sieve(n+1,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=sqrt(n);i++){
            for(int j=i*i;j<sieve.size();j+=i){
                sieve[j] = 0;
            }
        }
        vector<int> v;
        for(int i=0;i<sieve.size();i++){
            if(sieve[i]==1) v.push_back(i);
        }
        if(sieve[n]==1) return n;
        int original = n;
        while(true){
            int sum = 0;
            int product = 1;
            int num = n;
            for(int i=0;i<v.size();i++){
                int ele = v[i];
                while(num%ele==0 && num!=0){
                    sum = sum + ele;
                    product = product * ele;
                    num = num/ele;
                }
                if(product==n){
                    n = sum;
                    break;
                }
            }
            if(n==original) return original;
            if(sieve[n]==1) return n;
        }
        return n;
    }
};