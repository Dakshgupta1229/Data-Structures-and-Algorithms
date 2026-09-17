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
            while(v.size()<k && high>=0 && low<arr.size()){
                int distance1 = abs(arr[high] - x);
                int distance2 = abs(arr[low] - x);
                if(distance1<=distance2){
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
            int second = pivot_idx+1;
            while(v.size()<k && pivot_idx>=0 && second<arr.size()){
                int distance1 = abs(arr[pivot_idx] - x);
                int distance2 = abs(arr[second] - x);
                if(distance1<=distance2){
                    v.push_back(arr[pivot_idx]);
                    pivot_idx--;
                }
                else{
                    v.push_back(arr[second]);
                    second++;
                }
            }
            while(v.size()<k && pivot_idx>=0){
                v.push_back(arr[pivot_idx]);
                pivot_idx--;
            }
            while(v.size()<k && second<arr.size()){
                v.push_back(arr[second]);
                second++;
            }

        }
        sort(v.begin(),v.end());
        return v;
    }
};