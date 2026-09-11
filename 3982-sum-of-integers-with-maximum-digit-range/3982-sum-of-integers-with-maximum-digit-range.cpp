class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        map<int,int> m;
        int sum = 0;
        int max_diff = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int min_ele = INT_MAX;
            int max_ele = INT_MIN;
            while(num!=0){
                int digit = num%10;
                if(min_ele>digit) min_ele = digit;
                if(max_ele<digit) max_ele = digit;
                num = num/10;
            }
            int diff = max_ele - min_ele;
            m[nums[i]] = diff;
            if(max_diff<diff) max_diff = diff;
        }
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                if(m[nums[i]]==max_diff) sum = sum + nums[i];
            }
        }
        return sum;
    }
};