class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums[0]>=0){
            int sum = 0;
            if(k%2!=0) nums[0] = -(nums[0]);
            for(int i=0;i<nums.size();i++){
                sum = sum + nums[i];
            }
            return sum;
        }
        for(int i=0;i<nums.size();i++){
            if(k==0) break;
            if(nums[i]<0) nums[i] = -(nums[i]);
            else break;
            k--;
        }
        sort(nums.begin(),nums.end());
        if(k%2!=0) nums[0] = -nums[0];
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<endl;
            sum = sum + nums[i];
        }
        return sum;
    }
};