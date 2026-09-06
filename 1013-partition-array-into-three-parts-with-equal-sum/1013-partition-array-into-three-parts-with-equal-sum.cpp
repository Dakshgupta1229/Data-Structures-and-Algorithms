class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for(int i=0;i<arr.size();i++) sum = sum + arr[i];
        cout<<sum<<endl;
        if(sum%3!=0) return false;
        int parts = sum/3;
        int count = 0;
        int sum2 = 0;
        for(int i=0;i<arr.size();i++){
            sum2 = sum2 + arr[i];
            if(sum2==parts){
                sum2 = 0;
                count++;
            }
        }
        if(sum==0 && count>=3) return true;
        if(count>=3) return true;
        return false;
    }
};