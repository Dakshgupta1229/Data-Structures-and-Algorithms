class Solution {

    public boolean check(int[] piles,long mid,int h){
        long count = 0;
        for(int i=0;i<piles.length;i++){
            if(piles[i]<=mid) count++;
            else{
                count = count + piles[i]/mid;
                if(piles[i]%mid!=0) count++;
            }
        }
        if(count<=h) return true;
        return false;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int max_ele = Integer.MIN_VALUE;
        for(int i=0;i<piles.length;i++){
            if(max_ele<piles[i]){
                max_ele = piles[i];
            }
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