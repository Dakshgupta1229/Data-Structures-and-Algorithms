class Solution {

    int find(int num1,int num2){
        while(num1>0 && num2>0){
            if(num1>=num2) num1 = num1%num2;
            else num2 = num2%num1;
        }
        if(num1!=0) return num1;
        return num2;
    }
    int find_lcm(int num1,int num2){
        for(int i=Math.max(num1,num2);i<50000;i+=Math.max(num1,num2)){
            if(i%num1==0 && i%num2==0) return i;
        }
        return 1;
    }

    public int maxLength(int[] nums) {
        int max_length = 0;
        for(int i=0;i<nums.length;i++){
            int product = 1;
            int gcd = 0;
            int count = 0;
            int lcm = 1;
            for(int j=i;j<nums.length;j++){
                product = product * nums[j];
                gcd = find(gcd,nums[j]);
                lcm = find_lcm(lcm,nums[j]);
                if(product==(gcd * lcm)){
                    if(max_length<(j-i+1)) max_length = j-i+1;
                }
            }
        }
        return max_length;
    }
}