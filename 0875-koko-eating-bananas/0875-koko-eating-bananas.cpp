class Solution {
public:

    bool check(vector<int> &piles,long long mid,int h){
        long long count = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]<=mid) count++;
            else{
                count = count + (piles[i]/mid);
                if(piles[i]%mid!=0) count++;
            }
        }
        if(count<=h) return true;
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max_ele = INT_MIN;
        for(int i=0;i<piles.size();i++){
            if(max_ele<piles[i]) max_ele = piles[i];
        }
        int low = 1;
        int high = max_ele;
        int ans = -1;
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