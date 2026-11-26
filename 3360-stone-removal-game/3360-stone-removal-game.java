class Solution {
    public boolean canAliceWin(int n) {
        int result = -1;
        int initial = 10;
        while(n>0){
            if(n>=initial){
                n = n - initial;
                initial--;
                if(result==-1) result = 0;
                else if(result==0) result = 1;
                else result = 0;
            }
            else break;
        }
        if(result==0) return true;
        return false;
    }
}