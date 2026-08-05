class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int> sieve(100+1,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=sqrt(100);i++){
            for(int j=i*i;j<sieve.size();j+=i){
                sieve[j] = 0;
            }
        }
        int first = -1;
        int second = -1;
        for(int i=0;i<nums.size();i++){
            if(sieve[nums[i]]==1 && first==-1) first = i;
            if(sieve[nums[i]]==1) second = i;
        }
        return abs(second - first);
    }
};