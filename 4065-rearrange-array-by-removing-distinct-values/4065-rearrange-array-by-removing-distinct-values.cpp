class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        while(true){
            if(m.size()==0) break;
            vector<int> v1;
            for(auto p:m){
                int ele = p.first;
                int freq = p.second;
                v.push_back(ele);
                freq--;
                m[ele] = freq;
                if(freq==0) v1.push_back(ele);
            }
            for(int i=0;i<v1.size();i++){
                m.erase(v1[i]);
            }
        }
        return v;
    }
};