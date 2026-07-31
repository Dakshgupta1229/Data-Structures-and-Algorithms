class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid==0) low = mid + 1;
            else if(mid==arr.size()-1) high = mid - 1;
            else if(mid-1>=0 && mid+1<arr.size() && arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) return mid;
            else if(arr[mid]>arr[mid-1]) low = mid + 1;
            else high = mid - 1;

        }
        cout<<low<<" "<<high;
        return -1;
    }
};