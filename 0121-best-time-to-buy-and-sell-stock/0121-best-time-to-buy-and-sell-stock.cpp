class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> nge(prices.size());
        nge[prices.size()-1] = -1;
        int max_ele = prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            if(max_ele<prices[i]) max_ele = prices[i];
            nge[i] = max_ele;
        }
        int max_el = 0;
        for(int i=0;i<nge.size()-1;i++){
            int diff = nge[i] - prices[i];
            if(max_el<diff) max_el = diff;
        }
        return max_el;
    }
};