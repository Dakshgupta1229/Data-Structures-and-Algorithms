class Solution {
public:

    void traverse(string str,set<string> &s,int n,string &result){
        if(str.size()>n) return;
        if(str.size()==n){
            if(s.find(str)==s.end()) result = str;
            return;
        }
        if(result!="") return;
        traverse(str+'1',s,n,result);
        traverse(str+'0',s,n,result);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        set<string> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        string result;
        traverse("",s,nums.size(),result);
        return result;
    }
};