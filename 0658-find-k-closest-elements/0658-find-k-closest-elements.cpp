class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size()-1;
        int pivot_idx = -1;
        vector<int> result;
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
            while(high>=0 && low<arr.size() && result.size()!=k){
                int diff1 = abs(arr[high] - x);
                int diff2 = abs(arr[low] - x);
                if(diff1<=diff2){
                    result.push_back(arr[high]);
                    high--;
                }
                else{
                    result.push_back(arr[low]);
                    low++;
                }
            }
            while(result.size()!=k && high>=0){
                result.push_back(arr[high]);
                high--;
            }
            while(result.size()!=k && low<arr.size()){
                result.push_back(arr[low]);
                low++;
            }
            sort(result.begin(),result.end());

        }
        else{
            result.push_back(arr[pivot_idx]);
            low = pivot_idx-1;
            high = pivot_idx+1;
            while(result.size()!=k && low>=0 && high<arr.size()){
                int diff1 = abs(arr[low] - x);
                int diff2 = abs(arr[high] - x);
                if(diff1<=diff2){
                    result.push_back(arr[low]);
                    low--;
                }
                else{
                    result.push_back(arr[high]);
                    high++;
                }
            }
            while(result.size()!=k && low>=0){
                result.push_back(arr[low]);
                low--;
            }
            while(result.size()!=k && high<arr.size()){
                result.push_back(arr[high]);
                high++;
            }
            sort(result.begin(),result.end());
        }
        return result;
    }
};