class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        vector<int> v1;
        vector<int> v2;
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0;i<minutes;i++){
            sum1 = sum1 + customers[i];
            if(grumpy[i]==0) sum2 = sum2 + customers[i];
        }
        v1.push_back(sum1);
        v2.push_back(sum2);
        for(int i=1;i<=customers.size()-minutes;i++){
            sum1 = sum1 - customers[i-1];
            sum1 = sum1 + customers[i+minutes-1];
            if(grumpy[i-1]==0) sum2 = sum2 - customers[i-1];
            if(grumpy[i+minutes-1]==0) sum2 = sum2 + customers[i+minutes-1];
            v1.push_back(sum1);
            v2.push_back(sum2);
        }
        int idx = -1;
        int max_ele = INT_MIN;
        for(int i=0;i<v1.size();i++){
            if(max_ele<(v1[i]-v2[i])){
                max_ele = v1[i] - v2[i];
                idx = i;
            }
        }
        for(int i=idx;i<idx+minutes;i++){
            grumpy[i] = 0;
        }
        int result = 0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0) result = result + customers[i];
        }
        return result;
    }
};