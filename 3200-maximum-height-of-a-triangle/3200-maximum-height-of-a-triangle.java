class Solution {
    public int maxHeightOfTriangle(int red, int blue) {
        char ch = 'r';
        int count = 0;
        int red1 = red;
        int blue1 = blue;
        for(int i=1;i<=Math.max(red,blue);i++){
            if(ch=='r' && red1>=i){
                red1 = red1 - i;
                ch = 'b';
                count++;
            }
            else if(ch=='b' && blue1>=i){
                blue1 = blue1 - i;
                ch = 'r';
                count++;
            }
            else break;
        }
        char ch1 = 'b';
        int count2 = 0;
        red1 = red;
        blue1 = blue;
        for(int i=1;i<=Math.max(red,blue);i++){
            if(ch1=='b' && blue1>=i){
                blue1 = blue1 - i;
                ch1 = 'r';
                count2++;
            }
            else if(ch1=='r' && red1>=i){
                red1 = red1 - i;
                ch1 = 'b';
                count2++;
            }
            else break;
        }
        return Math.max(count,count2);
    }
}