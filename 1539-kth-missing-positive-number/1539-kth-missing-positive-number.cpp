class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int> s;
        for(int i=0;i<arr.size();i++) s.insert(arr[i]);
        for(int i=1;i<=1000000;i++){
            if(s.find(i)==s.end()) k--;
            if(k==0) return i;
        }
        return arr.size()+1;
    }
};