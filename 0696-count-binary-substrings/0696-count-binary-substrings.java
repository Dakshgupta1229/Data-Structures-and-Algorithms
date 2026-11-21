class Solution {
    public int countBinarySubstrings(String s) {
        int count_zero = 0;
        int count_one = 0;
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='0'){
                if(count_one!=0){
                    list.add(count_one);
                    count_one = 0;
                }
                count_zero++;
            }
            else{
                if(count_zero!=0){
                    list.add(count_zero);
                    count_zero = 0;
                }
                count_one++;
            }
            
        }
        if(count_zero!=0) list.add(count_zero);
        if(count_one!=0) list.add(count_one);
        int sum = 0;
        for(int i=0;i<list.size()-1;i++){
            sum = sum + Math.min(list.get(i),list.get(i+1));
        }
        return sum;
    }
}