class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        int count = 0;
        for(auto p:m){
            int ele = p.first;
            vector<int> v = p.second;
            if(v.size()==3){
                int space = v[1] - v[0];
                bool flag = true;
                for(int i=1;i<v.size();i++){
                    if(v[i]-v[i-1]!=space){
                        flag = false;
                        break;
                    }
                }
                if(flag==true) count++;
            }
        }
        return count;
    }
};