class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int window_size = customers.size()-minutes;
        vector<int> v1;
        vector<int> v2;
        int sum = 0;
        int sum2 = 0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==0) sum = sum + customers[i];
            sum2 = sum2 + customers[i];
        }
        v1.push_back(sum);
        v2.push_back(sum2);
        for(int i=1;i<=window_size;i++){
            if(grumpy[i-1]==0) sum = sum - customers[i-1];
            if(grumpy[i+minutes-1]==0) sum = sum + customers[i+minutes-1];
            v1.push_back(sum);
            sum2 = sum2 - customers[i-1];
            sum2 = sum2 + customers[i+minutes-1];
            v2.push_back(sum2);
        }
        int diff = INT_MIN;
        int idx = -1;
        for(int i=0;i<v1.size();i++){
            if(diff<abs(v2[i]-v1[i])){
                diff = abs(v2[i] - v1[i]);
                idx = i;
            }
        }
        for(int i=idx;i<minutes+idx;i++){
            grumpy[i] = 0;
        }
        int result = 0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0) result += customers[i];
        }

        return result;
    }
};