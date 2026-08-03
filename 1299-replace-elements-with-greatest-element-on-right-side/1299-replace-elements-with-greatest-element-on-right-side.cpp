class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> v(arr.size());
        v[arr.size()-1] = -1;
        int max_ele = arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--){
            v[i] = max_ele;
            if(max_ele<arr[i]) max_ele = arr[i];
        }
        return v;
    }
};