class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<int> v;
        for(int i=0;i<number.size();i++){
            if(number[i]==digit) v.push_back(i);
        }
        vector<string> v1;
        for(int i=0;i<v.size();i++){
            int idx = v[i];
            string result1 = number.substr(0,idx);
            string result2 = number.substr(idx+1);
            v1.push_back(result1 + result2);
        }
        sort(v1.begin(),v1.end());
        return v1[v1.size()-1];
    }
};