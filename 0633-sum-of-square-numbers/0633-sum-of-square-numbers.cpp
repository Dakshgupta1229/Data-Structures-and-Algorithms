class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0;
        int j = sqrt(c);
        while(i<=j){
            long long num1 = (long long)i * (long long)i;
            long long num2 = (long long)j * (long long)j;
            if(num1+num2==c) return true;
            else if(num1+num2>c) j--;
            else i++;
        }
        return false;
    }
};