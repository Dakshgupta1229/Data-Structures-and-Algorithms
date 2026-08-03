class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int result = 0;
        for(int i=0;i<arr.size();i++){
            int count = 0;
            int sum = 0;
            for(int j=i;j<arr.size();j++){
                sum = sum + arr[j];
                count++;
                if(count%2!=0) result = result + sum;
            }
        }

        return result;
    }
};