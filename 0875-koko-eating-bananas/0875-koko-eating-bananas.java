class Solution {

    boolean check(int[] piles,long mid,int h){
        long count = 0;
        for(int i=0;i<piles.length;i++){
            if((long)piles[i]<=mid) count++;
            else if((long)piles[i]%mid==0) count = count + ((long)piles[i]/mid);
            else count = count + ((long)piles[i]/mid) + 1;
        }
        if(count<=(long)h) return true;
        return false;
    }

    public int minEatingSpeed(int[] piles, int h) {
        long max_ele = Long.MIN_VALUE;
        for(int i=0;i<piles.length;i++){
            if(max_ele<(long)piles[i]) max_ele = (long)piles[i];
        }
        long low = 1;
        long high = max_ele;
        long ans = -1;
        while(low<=high){
            long mid = low + (high-low)/2;
            if(check(piles,mid,h)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return (int)ans;
    }
}