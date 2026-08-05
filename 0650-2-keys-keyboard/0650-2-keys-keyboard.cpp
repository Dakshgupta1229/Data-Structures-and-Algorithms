class Solution {
public:
    int minSteps(int n) {
        int count = 0;
        while(n!=1){
            int divisor = 1;
            for(int i=2;i<=sqrt(n);i++){
                if(n%i==0){
                    divisor = i;
                    break;
                }
            }
            if(divisor==1){
                count = count + n;
                break;
            }
            count = count + (n/(n/divisor));
            n = n/divisor;
        }
        return count;
    }
};