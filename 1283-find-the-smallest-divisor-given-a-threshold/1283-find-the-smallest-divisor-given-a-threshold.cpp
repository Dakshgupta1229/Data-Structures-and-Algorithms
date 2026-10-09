class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = 1000000;
        int result = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int sum = 0;
            for(int i=0;i<nums.size();i++){
                float ele = (float)nums[i]/(float)mid;
                sum = sum + (int)ceil(ele);
            }
            if(sum<=threshold){
                result = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return result;
    }
};