class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> sieve(right+1,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=sqrt(right);i++){
            for(int j=i*i;j<sieve.size();j+=i){
                sieve[j] = 0;
            }
        }
        vector<int> v;
        for(int i=left;i<=right;i++){
            if(sieve[i]==1) v.push_back(i);
        }
        if(v.size()<=1) return {-1,-1};
        int first = v[0];
        int min_diff = INT_MAX;
        int res1 = -1;
        int res2 = -1;
        for(int i=1;i<v.size();i++){
            int second = v[i];
            if(min_diff>second-first){
                min_diff = second - first;
                res1 = first;
                res2 = second;
            }
            first = second;
        }
        return {res1,res2};
    }
};