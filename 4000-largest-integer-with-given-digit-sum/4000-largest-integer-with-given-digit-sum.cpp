class Solution {
public:
    int largestInteger(int n, int s) {
        for(int i=pow(10,n)-1;i>=0;i--){
            int num = i;
            int sum = 0;
            while(num!=0){
                sum = sum + num%10;
                num = num/10;
            }
            if(sum==s) return i;
        }
        return -1;
    }
};