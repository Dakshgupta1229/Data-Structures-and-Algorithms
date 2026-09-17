class Solution {
public:

    bool check(vector<int> &piles,long long mid,long long h){
        long long count = 0;
        for(int i=0;i<piles.size();i++){
            if((long long)piles[i]<=mid) count++;
            else if((long long)piles[i]%mid==0) count = count + ((long long)piles[i]/mid);
            else count = count + ((long long)piles[i]/mid) + 1;
        }
        if(count<=h) return true;
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max_ele = INT_MIN;
        for(int i=0;i<piles.size();i++){
            if(max_ele<piles[i]) max_ele = piles[i];
        }
        long long low = 1;
        long long high = max_ele;
        long long ans = -1;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(check(piles,mid,h)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};