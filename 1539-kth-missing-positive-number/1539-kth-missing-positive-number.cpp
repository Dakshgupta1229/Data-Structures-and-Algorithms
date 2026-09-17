class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int> s;
        for(int i=0;i<arr.size();i++) s.insert(arr[i]);
        int count = 0;
        for(int i=1;i<=1000+k;i++){
            if(s.find(i)==s.end()){
                count++;
            }
            if(count==k) return i;
        }
        return arr.size()+1;
    }
};