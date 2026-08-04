class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for(int i=1;i<=sqrt(num);i++){
            if(num%i==0){
                if(i==num/i){
                    if(i!=num) sum = sum + i;
                }
                else{
                    if(i!=num) sum = sum + i;
                    if((num/i)!=num) sum = sum + num/i;
                }
            }
        }
        if(sum==num) return true;
        return false;
    }
};