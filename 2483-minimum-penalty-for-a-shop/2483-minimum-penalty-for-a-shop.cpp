class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> prefix(customers.size()+1);
        vector<int> suffix(customers.size()+1);
        prefix[0] = 0;
        suffix[suffix.size()-1] = 0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='N') prefix[i+1] = prefix[i] + 1;
            else prefix[i+1] = prefix[i];
        }
        for(int i=customers.size()-1;i>=0;i--){
            if(customers[i]=='Y') suffix[i] = suffix[i+1] + 1;
            else suffix[i] = suffix[i+1];
        }
        int min_ele = INT_MAX;
        int idx = -1;
        for(int i=0;i<prefix.size();i++){
            if(min_ele>(prefix[i]+suffix[i])){
                min_ele = prefix[i] + suffix[i];
                idx = i;
            }
        }
        return idx;
    }
};