class Solution {
public:

    bool check(int num){
        bool flag = true;
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                flag = false;
                break;
            }
        }
        if(num==1) return false;
        if(flag==true) return true;
        return false;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        int c1 = 0;
        int c2 = nums.size()-1;
        int max_ele = 0;
        for(int i=0;i<nums.size();i++){
            if(c1==c2){
                if(check(nums[i][c1])){
                    if(max_ele<nums[i][c1]) max_ele = nums[i][c1];
                }
            }
            else{
                if(check(nums[i][c1])){
                    if(max_ele<nums[i][c1]) max_ele = nums[i][c1];
                }
                if(check(nums[i][c2])){
                    if(max_ele<nums[i][c2]) max_ele = nums[i][c2];
                }
            }
            c1++;
            c2--;
        }
        return max_ele;
    }
};