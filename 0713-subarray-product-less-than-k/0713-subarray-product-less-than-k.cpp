class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int i=0;
        int j=0;
        long long product = 1;
        int count = 0;
        while(j<nums.size()){
            product = product * nums[j];
            while(product>=k && i<nums.size()){
                count = count + (j-i);
                product = product/(long long)nums[i];
                i++;
            }
            j++;
        }
        while(i<nums.size() && product<k){
            count = count + (j-i);
            product = product/nums[i];
            i++;
        }
        return count;
        
    }
};