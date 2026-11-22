class Solution {
    public int findTheLongestBalancedSubstring(String s) {
        int max_length = 0;
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            boolean flag1 = true;
            boolean flag2 = true;
            int count_zero = 0;
            int count_one = 0;
            if(ch=='0'){
                for(int j=i;j<s.length();j++){
                    char ch2 = s.charAt(j);
                    if(ch2=='0' && flag1==true){
                        count_zero++;
                    }
                    else if(ch2=='1'){
                        flag1 = false;
                        count_one++;
                    }
                    else{
                        if(max_length<Math.min(count_zero,count_one) + Math.min(count_zero,count_one)) max_length = Math.min(count_zero,count_one) + Math.min(count_zero,count_one);
                        break;
                    }
                }
                if(max_length<Math.min(count_zero,count_one)+Math.min(count_zero,count_one)) max_length = Math.min(count_zero,count_one) + Math.min(count_zero,count_one);
            }
        }
        return max_length;
    }
}