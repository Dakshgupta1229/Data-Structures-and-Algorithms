class Solution {
    public int maxProfit(int[] prices) {
        int ele = -1;
        int max_profit = 0;
        int[] next_greatest = new int[prices.length];
        next_greatest[prices.length-1] = ele;
        for(int i=prices.length-1;i>=1;i--){
            if(ele<prices[i]) ele = prices[i];
            next_greatest[i-1] = ele;
        }
        for(int i=0;i<prices.length-1;i++){
            if(max_profit < (next_greatest[i] - prices[i])) max_profit = next_greatest[i] - prices[i];
        }
        return max_profit;
    }
}