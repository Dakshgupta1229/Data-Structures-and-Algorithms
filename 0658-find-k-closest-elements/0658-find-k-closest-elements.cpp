class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> v;
        int pivot_idx = -1;
        int low = 0;
        int high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]==x){
                pivot_idx = mid;
                break;
            }
            else if(arr[mid]>x) high = mid - 1;
            else low = mid + 1;
        }
        if(pivot_idx==-1) pivot_idx = high;

        if(pivot_idx==-1){
            int idx = 0;
            while(v.size()<k){
                v.push_back(arr[idx]);
                idx++;
            }
        }
        else{
            int i=pivot_idx;
            int j=pivot_idx+1;
            while(i>=0 && j<arr.size() && v.size()<k){
                int dist1 = abs(arr[i]-x);
                int dist2 = abs(arr[j]-x);
                if(dist1<dist2){
                    v.push_back(arr[i]);
                    i--;
                }
                else if(dist1>dist2){
                    v.push_back(arr[j]);
                    j++;
                }
                else{
                    v.push_back(arr[i]);
                    i--;
                }
            }
            while(v.size()<k && i>=0){
                v.push_back(arr[i]);
                i--;
            }
            while(v.size()<k && j<arr.size()){
                v.push_back(arr[j]);
                j++;
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};