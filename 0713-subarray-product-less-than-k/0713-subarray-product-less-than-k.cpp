class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long product = 1;
        int i=0;
        int j=0;
        int count = 0;
        while(j<nums.size()){
            product = product * nums[j];
            while(product>=k && i<nums.size()){
                count = count + (j-i);
                product = product/nums[i];
                i++;
            }
            j++;
        }
        while(i<nums.size()){
            count = count + (j-i);
            product = product/nums[i];
            i++;
        }
        return count;
    }
};