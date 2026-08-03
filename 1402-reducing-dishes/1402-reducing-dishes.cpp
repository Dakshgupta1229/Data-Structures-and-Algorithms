class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<int> suffix = satisfaction;
        int idx = -1;
        for(int i=satisfaction.size()-2;i>=0;i--){
            suffix[i] = suffix[i] + suffix[i+1];
        }
        for(int i=0;i<satisfaction.size();i++){
            if(suffix[i]>=0){
                idx = i;
                break;
            }
        }
        int n = 1;
        int sum = 0;
        for(int i=idx;i<satisfaction.size();i++){
            sum = sum + (satisfaction[i] * n);
            n++;
        }
        return sum;

        return 1;
    }
};