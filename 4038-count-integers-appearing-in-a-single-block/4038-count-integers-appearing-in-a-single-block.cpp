class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,vector<int>> m;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        for(auto p:m){
            vector<int> v = p.second;
            int ele = v[0];
            bool flag = true;
            for(int i=1;i<v.size();i++){
                if(v[i]-ele==1){
                    ele = v[i];
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag==true) count++;
        }
        return count;
    }
};