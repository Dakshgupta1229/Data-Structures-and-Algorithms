class Solution {
public:

    void generate(set<string> &s,string str,int &n,string &result){
        if(result.size()!=0) return;
        if(str.size()==n){
            if(s.find(str)==s.end()){
                result = str;
                return;
            }
        }
        if(str.size()>n) return;
        generate(s,str+'0',n,result);
        generate(s,str+'1',n,result);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        set<string> s;
        string result;
        for(int i=0;i<nums.size();i++) s.insert(nums[i]);
        generate(s,"",n,result);
        return result;
    }
};