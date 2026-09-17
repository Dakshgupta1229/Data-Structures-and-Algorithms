class Solution {
public:

    bool check(vector<int> &weights,int mid,int days){
        int sum = 0;
        int count = 0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]<=mid){
                sum = sum + weights[i];
            }
            else{
                count++;
                sum = weights[i];
            }
        }
        if(sum!=0) count++;
        if(count<=days) return true;
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int max_ele = INT_MIN;
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            if(max_ele<weights[i]) max_ele = weights[i];
            sum = sum + weights[i];
        }
        int low = max_ele;
        int high = sum;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(weights,mid,days)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};