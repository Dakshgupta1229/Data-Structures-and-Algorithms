class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max = INT_MIN;
        int count = 0;
        int count2 = 0;
        int max2 = INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                count++;
                if(max<count){
                    max = count;
                }
            }
            else{
                count = 0;
            }
            if(nums[i]>nums[i+1]){
                count2++;
                if(max2<count2){
                    max2 = count2;
                }
            }
            else{
                count2 = 0;
            }
        }
        if(max==INT_MIN){
            max = 1;
        }
        else{
            max = max + 1;
        }
        if(max2==INT_MIN){
            max2 = 1;
        }
        else{
            max2 = max2 + 1;
        }
        if(max>=max2){
            return max;
        }
        else{
            return max2;
        }
    }
};