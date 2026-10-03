class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0;
        int b= sqrt(c);
        while(a<=b){
            long long first = a * a;
            long long second = b * b;
            long long sum = first + second;
            if(sum==c) return true;
            else if(sum>c) b--;
            else a++;
        }
        return false;
    }
};