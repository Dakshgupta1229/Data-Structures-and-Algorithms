class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        double sum = 0;
        int count = 0;
        for(int i=0;i<k;i++){
            sum = sum + (double)arr[i];
        }
        double n = (double)k;
        if(sum/n>=(double)threshold) count++;
        for(int i=1;i<=arr.size()-k;i++){
            sum = sum - (double)arr[i-1];
            sum = sum + (double)arr[i+k-1];
            if(sum/n>=(double)threshold) count++;
        }
        return count;
    }
};