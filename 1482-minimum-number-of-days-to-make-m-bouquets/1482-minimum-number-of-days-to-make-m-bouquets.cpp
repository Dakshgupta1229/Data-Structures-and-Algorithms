class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int min_ele = INT_MAX;
        int max_ele = INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            if(min_ele>bloomDay[i]) min_ele = bloomDay[i];
            if(max_ele<bloomDay[i]) max_ele = bloomDay[i];
        }

        int low = min_ele;
        int high = max_ele;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int count = 0;
            int pairs = 0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    count++;
                }
                else count = 0;
                if(count==k){
                    pairs++;
                    count = 0;
                }
            }
            if(pairs>=m){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};