class Solution {
public:

    bool check(vector<int> &weights,int w,int days){
        int count = 0;
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]<=w){
                sum = sum + weights[i];
            }
            else{
                count++;
                sum = 0;
                sum += weights[i];
            }
        }
        if(sum!=0) count++;
        if(count<=days) return true;
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int ans = -1;
        int max_ele = INT_MIN;
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            if(max_ele<weights[i]) max_ele = weights[i];
            sum = sum + weights[i];
        }
        int low = max_ele;
        int high = sum;
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