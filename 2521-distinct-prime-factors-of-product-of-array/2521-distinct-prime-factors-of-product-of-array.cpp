class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int max_ele = INT_MIN;
        set<int> s;
        for(int i=0;i<nums.size();i++){
            if(max_ele<nums[i]) max_ele = nums[i];
        }
        vector<bool> sieve(max_ele+1,1);
        vector<int> v;
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=sqrt(max_ele);i++){
            for(int j=i*i;j<=sieve.size();j+=i){
                sieve[j] = 0;
            }
        }
        for(int i=0;i<sieve.size();i++){
            if(sieve[i]==1) v.push_back(i);
        }
        for(int i=0;i<nums.size();i++){
            int ele = nums[i];
            for(int i=0;i<v.size();i++){
                while(ele%v[i]==0 && ele!=0){
                    s.insert(v[i]);
                    ele = ele/v[i];
                }
            }
        }
        return s.size();
    }
};