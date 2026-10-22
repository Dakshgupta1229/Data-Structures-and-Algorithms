class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<boxTypes.size();i++){
            int value1 = boxTypes[i][0];
            int value2 = boxTypes[i][1];
            pq.push({value2,value1});
        }
        int sum = 0;
        while(pq.size()>0){
            int value1 = pq.top().first;
            int value2 = pq.top().second;
            pq.pop();
            if(value2<=truckSize){
                cout<<value2*value1<<endl;
                sum = sum + (value2 * value1);
                truckSize -= value2;
            }
            else{
                sum = sum + (value1 * truckSize);
                break;
            }
        }
        return sum;
    }
};