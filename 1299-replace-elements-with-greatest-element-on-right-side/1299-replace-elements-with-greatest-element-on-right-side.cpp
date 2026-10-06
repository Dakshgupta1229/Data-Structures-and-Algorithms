class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max_ele = arr[arr.size()-1];
        arr[arr.size()-1] = -1;
        for(int i=arr.size()-2;i>=0;i--){
            int ele = arr[i];
            arr[i] = max_ele;
            if(max_ele<ele) max_ele = ele;
        }
        return arr;
    }
};