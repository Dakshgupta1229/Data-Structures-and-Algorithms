class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> sieve(right+1,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=sqrt(right);i++){
            for(int j=i*i;j<=right;j+=i){
                sieve[j] = 0;
            }
        }
        int min_dist = INT_MAX;
        int first = -1;
        int second = -1;
        int s1 = -1;
        int s2 = -1;
        for(int i=left;i<=right;i++){
            if(sieve[i]==1 && first==-1){
                first = i;
            }
            else if(sieve[i]==1 && second==-1){
                second = i;
                if(min_dist>(second-first)){
                    min_dist = second - first;
                    s1 = first;
                    s2 = second;
                }
                first = i;
                second = -1;
            }
        }
        return {s1,s2};
    }
};