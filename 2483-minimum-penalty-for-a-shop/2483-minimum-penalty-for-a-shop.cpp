class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> prefix(customers.size()+1);
        vector<int> suffix(customers.size()+1);
        prefix[0] = 0;
        suffix[suffix.size()-1] = 0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y') prefix[i+1] = 0 + prefix[i];
            else prefix[i+1] = 1 + prefix[i];
        }
        for(int i=customers.size()-1;i>=0;i--){
            if(customers[i]=='N') suffix[i] = 0 + suffix[i+1];
            else suffix[i] = 1 + suffix[i+1];
        }
        int minimum = INT_MAX;
        int idx = -1;
        for(int i=0;i<prefix.size();i++){
            if(minimum>(prefix[i] + suffix[i])){
                minimum = prefix[i] + suffix[i];
                idx = i;
            }
        }
        return idx;
    }
};