class Solution {
public:
    long long splitArray(vector<int>& nums) {
        vector<bool> sieve(nums.size()+1,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=sqrt(nums.size());i++){
            for(int j=i*i;j<nums.size();j+=i){
                sieve[j] = 0;
            }
        }
        long long sum1 = 0;
        long long sum2 = 0;
        for(int i=0;i<nums.size();i++){
            if(sieve[i]==1) sum1 = sum1 + (long long)nums[i];
            else sum2 = sum2 + (long long)nums[i];
        }
        return abs(sum1 - sum2);
    }
};