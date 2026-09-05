class Solution {
public:

    int check(vector<int> &weights,int days,int mid){
        int sum = 0;
        int count = 0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]<=mid){
                sum = sum + weights[i];
            }
            else{
                sum = weights[i];
                count++;
            }
        }
        if(sum!=0) count++;
        return count;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int max_ele = INT_MIN;
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            if(max_ele<weights[i]) max_ele = weights[i];
            sum = sum + weights[i];
        }
        long long low = max_ele;
        long long high = sum;
        int ans = -1;
        while(low<=high){
            long long mid = low + (high-low)/2;
            int count = check(weights,days,(int)mid);
            if(count<=days){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};