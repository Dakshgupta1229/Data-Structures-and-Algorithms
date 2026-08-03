class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int count = 0;
        int window_size = arr.size()-k;
        for(int i=0;i<k;i++) sum = sum + arr[i];
        if((sum/k)>=threshold) count++;
        for(int i=1;i<=window_size;i++){
            sum = sum - arr[i-1];
            sum = sum + arr[i+k-1];
            if((sum/k)>=threshold) count++;
        }
        return count;
    }
};