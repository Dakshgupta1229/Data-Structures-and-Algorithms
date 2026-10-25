class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count = 0;
        for(int i=0;i<intervals.size();i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            for(int j=i+1;j<intervals.size();j++){
                int start = intervals[j][0];
                int end = intervals[j][1];
                if(start<=e) count++;
                else break;
            }
        }
        return count;
    }
};