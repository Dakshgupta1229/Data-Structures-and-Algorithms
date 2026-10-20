class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> v;
        vector<bool> sieve(n+1,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=sqrt(n);i++){
            for(int j=i*i;j<sieve.size();j+=i){
                sieve[j] = 0;
            }
        }
        vector<int> v1;
        for(int i=0;i<sieve.size();i++){
            if(sieve[i]==1) v1.push_back(i);
        }
        if(v1.size()<=1) return v;
        int i=0;
        int j=v1.size()-1;
        while(i<=j){
            int sum = v1[i] + v1[j];
            if(sum==n){
                v.push_back({v1[i],v1[j]});
                i++;
                j--;
            }
            else if(sum>n) j--;
            else i++;
        }
        return v;
    }
};