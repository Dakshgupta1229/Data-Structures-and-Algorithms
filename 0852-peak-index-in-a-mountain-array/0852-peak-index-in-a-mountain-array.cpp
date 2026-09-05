class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size()-1;
        int idx = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid==0) low++;
            else if(mid==arr.size()) high--;
            else if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                idx = mid;
                break;
            }
            else if(arr[mid]>arr[mid-1]) low = mid + 1;
            else high = mid -1;
        }
        return idx;
    }
};