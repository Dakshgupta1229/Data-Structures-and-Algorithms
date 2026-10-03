class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> v;
        int low = 0;
        int high = arr.size()-1;
        int pivot_idx = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]==x){
                pivot_idx = mid;
                break;
            }
            else if(arr[mid]>x) high = mid - 1;
            else low = mid + 1;
        }
        if(pivot_idx==-1){
            while(high>=0 && low<arr.size() && v.size()<k){
                if(abs(arr[high]-x)<=abs(arr[low]-x)){
                    v.push_back(arr[high]);
                    high--;
                }
                else{
                    v.push_back(arr[low]);
                    low++;
                }
            }
            while(v.size()<k && high>=0){
                v.push_back(arr[high]);
                high--;
            }
            while(v.size()<k && low<arr.size()){
                v.push_back(arr[low]);
                low++;
            }
        }
        else{
            low = pivot_idx;
            high = pivot_idx+1;
            while(low>=0 && high<arr.size() && v.size()<k){
                if(abs(arr[low]-x)<=abs(arr[high]-x)){
                    v.push_back(arr[low]);
                    low--;
                }
                else{
                    v.push_back(arr[high]);
                    high++;
                }
            }
            while(v.size()<k && low>=0){
                v.push_back(arr[low]);
                low--;
            }
            while(v.size()<k && high<arr.size()){
                v.push_back(arr[high]);
                high++;
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};