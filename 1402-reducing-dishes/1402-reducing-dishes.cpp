class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<int> suffix = satisfaction;
        for(int i=suffix.size()-2;i>=0;i--){
            suffix[i] = suffix[i] + suffix[i+1];
        }
        int idx = -1;
        for(int i=suffix.size()-1;i>=0;i--){
            if(suffix[i]<0){
                idx = i;
                break;
            }
        }
        int sum = 0;
        int cnt = 1;
        for(int i=idx+1;i<satisfaction.size();i++){
            sum = sum + (satisfaction[i]*cnt);
            cnt++;
        }
        return sum;
    }
};