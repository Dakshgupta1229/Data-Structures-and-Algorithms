class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0;
        long long b = sqrt(c);
        while(a<=b){
            long long num1 = a * a;
            long long num2 = b * b;
            if(num1 + num2==c) return true;
            else if(num1+num2>c) b--;
            else a++;
        }
        return false;
    }
};