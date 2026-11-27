class Solution {
    public int maxProfit(int[] prices) {
        int max_profit = 0;
        int next_greater = prices[prices.length-1];
        for(int i=prices.length-2;i>=0;i--){
            if(prices[i]<=next_greater){
                if(max_profit<next_greater-prices[i]){
                    max_profit = next_greater - prices[i];
                }
            }
            if(next_greater<prices[i]) next_greater = prices[i];
        }
        return max_profit;
    }
}