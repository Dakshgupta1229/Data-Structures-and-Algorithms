class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int start = INT_MIN;
        int count = 1;
        int max_len = 0;
        for(auto p:s){
            cout<<p<<" ";
        }
        cout<<endl;
        for(auto p:s){
            if(start==INT_MIN) start = p;
            else if(p-start==1){
                count++;
                start = p;
            }
            else{
                if(max_len<count) max_len = count;
                count = 1;
                start = p;
            }
        }
        if(max_len<count) max_len = count;
        return max_len;
    }
};