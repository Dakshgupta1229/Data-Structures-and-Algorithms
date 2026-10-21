class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float,vector<int>>> pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                float value = (float)arr[i]/arr[j];
                pq.push({value,{arr[i],arr[j]}});
                if(pq.size()>k) pq.pop();
            }
        }
        vector<int> v = pq.top().second;
        return v;
    }
};