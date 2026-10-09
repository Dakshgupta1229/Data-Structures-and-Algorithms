class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int max_ele = Integer.MIN_VALUE;
        for(int i=0;i<bloomDay.length;i++){
            if(max_ele<bloomDay[i]) max_ele = bloomDay[i];
        }
        int low = 1;
        int high = max_ele;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int count = 0;
            int pairs = 0;
            for(int i=0;i<bloomDay.length;i++){
                if(bloomDay[i]<=mid){
                    count++;
                }
                else count = 0;
                if(count>=k){
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
}