class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low = 0;
        long high = sqrt(c);
        while(low<=high){
            long long result = low * low + high * high;
            if(result==c) return true;
            else if(result>c) high--;
            else low++;
        }
        return false;
    }
};