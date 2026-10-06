class Solution {
    public int maxProfit(int[] prices) {
        int max_profit = 0;
        int last = 0;
        for(int i=prices.length-1;i>=0;i--){
            if(last>=prices[i] && max_profit<last-prices[i]){
                max_profit = last - prices[i];
            }
            if(last<prices[i]) last = prices[i];
        }
        return max_profit;
    }
}