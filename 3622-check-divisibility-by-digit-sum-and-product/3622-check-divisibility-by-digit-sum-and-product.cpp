class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int num = n;
        while(num!=0){
            sum = sum + num%10;
            product = product * (num%10);
            num = num/10;
        }
        int total = sum + product;
        if(n%total==0) return true;
        return false;
    }
};