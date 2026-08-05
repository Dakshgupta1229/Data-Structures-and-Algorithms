class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int max_ele = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(max_ele<nums[i]) max_ele = nums[i];
        }
        vector<int> sieve(max_ele+1,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=sqrt(max_ele);i++){
            for(int j=i*i;j<max_ele;j+=i){
                sieve[j] = 0;
            }
        }
        vector<int> v;
        for(int i=0;i<sieve.size();i++){
            if(sieve[i]==1) v.push_back(i);
        }
        set<int> s;
        for(int i=0;i<nums.size();i++){
            int ele = nums[i];
            for(int j=0;j<v.size();j++){
                while(ele%v[j]==0 && ele!=0){
                    s.insert(v[j]);
                    ele = ele/v[j];
                }
            }
        }
        return s.size();
    }
};