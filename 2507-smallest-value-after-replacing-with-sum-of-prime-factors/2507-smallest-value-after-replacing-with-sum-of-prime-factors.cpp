class Solution {
public:

    bool prime(int num){
        bool flag = true;
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                flag = false;
                break;
            }
        }
        if(flag==true && num!=1) return true;
        return false;
    }

    int smallestValue(int n) {
        int original = n;
        while(true){
            int sum = 0;
            for(int i=2;i<=n;i++){
                if(n%i==0 && prime(i)){
                    while(n%i==0){
                        sum = sum + i;
                        n = n/i;
                    }
                }
                if(n==1) break;
            }
            if(sum==original) return original;
            n = sum;
            if(prime(sum)) return sum;
        }
        return 1;
    }
};