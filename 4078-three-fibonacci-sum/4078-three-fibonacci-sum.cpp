class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a = 0;
        int b = 1;
        for(int i=0;i<n;i++){
            cout<<a<<" "<<b<<endl;
            int sum = a + b;
            if((sum+sum)==n) return true;
            if((sum+sum)>n) break;
            a = b;
            b = sum;
        }
        return false;
    }
};