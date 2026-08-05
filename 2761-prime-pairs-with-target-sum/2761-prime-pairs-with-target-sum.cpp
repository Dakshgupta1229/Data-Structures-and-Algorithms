class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> result;
        vector<int> sieve(n+1,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=sqrt(n);i++){
            for(int j=i*i;j<=n;j+=i){
                sieve[j] = 0;
            }
        }
        vector<int> v;
        for(int i=0;i<sieve.size();i++){
            if(sieve[i]==1) v.push_back(i);
        }
        int i=0;
        int j=v.size()-1;
        while(i<=j){
            if(v[i]+v[j]==n){
                result.push_back({v[i],v[j]});
                i++;
            }
            else if(v[i]+v[j]>n) j--;
            else i++;
        }
        return result;
    }
};