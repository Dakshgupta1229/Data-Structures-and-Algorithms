class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int count = 0;
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            int sum1 = 0;
            for(int j=i;j<arr.size();j++){
                sum1 += arr[j];
                if((j-i)%2==0) sum = sum + sum1;
            }
        }
        return sum;
    }
};