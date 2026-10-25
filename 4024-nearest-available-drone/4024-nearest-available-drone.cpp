class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int idx = -1;
        int max_sum = INT_MAX;
        for(int i=0;i<drones.size();i++){
            int x1 = drones[i][0];
            int y1 = drones[i][1];
            int t = drones[i][2];
            int sum = abs(target[0] - x1) + abs(target[1] - y1);
            if(sum<=t && max_sum>sum){
                idx = i;
                max_sum = sum;
            }
        }
        return idx;
    }
};