class Solution {
public:

    long long check(vector<int> &piles,long long h,long long mid){
        long long count = 0;
        for(int i=0;i<piles.size();i++){
            if((long long)piles[i]<=mid) count++;
            else if((long long)piles[i]%mid==0) count = count + ((long long)piles[i]/mid);
            else count = count + ((long long)piles[i]/mid) + 1;
        }
        return count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long max_ele = LLONG_MIN;
        for(int i=0;i<piles.size();i++){
            if(max_ele<piles[i]) max_ele = piles[i];
        }
        long long high = max_ele;
        long long ans = -1;
        while(low<=high){
            long long mid = low + (high-low)/2;
            long long count = check(piles,h,mid);
            if(count<=(long long)h){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return (int)ans;
    }
};