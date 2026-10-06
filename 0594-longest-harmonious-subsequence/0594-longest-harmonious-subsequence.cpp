class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max_length = 0;
        map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        int ele1 = -1;
        int num1 = -1;
        for(auto p:m){
            vector<int> v = p.second;
            if(ele1==-1 && num1==-1){
                ele1 = v[0];
                num1 = p.first;
            }
            else{
                int ele2 = v[v.size()-1];
                int length = ele2 - ele1 + 1;
                int num2 = p.first;
                if(max_length<length && num2-num1==1) max_length = length;
                ele1 = v[0];
                num1 = p.first;
            }
        }
        return max_length;
    }
};