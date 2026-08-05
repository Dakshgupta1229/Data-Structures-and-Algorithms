class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> sieve(n+1,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=sqrt(n);i++){
            for(int j=i*i;j<=n;j+=i){
                sieve[j] = 0;
            }
        }
        long long sum1 = 0;
        long long sum2 = 0;
        for(int i=0;i<nums.size();i++){
            if(sieve[i]==1) sum1 = sum1 + nums[i];
            else sum2 = sum2 + nums[i];
        }
        return abs(sum1-sum2);
    }
};