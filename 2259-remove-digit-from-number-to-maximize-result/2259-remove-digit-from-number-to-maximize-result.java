class Solution {
    public String removeDigit(String number, char digit) {
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<number.length();i++){
            if(number.charAt(i)==digit){
                list.add(i);
            }
        }
        List<String> list2 = new ArrayList<>();
        for(int i=0;i<list.size();i++){
            int idx = list.get(i);
            String result1 = number.substring(0,idx);
            String result2 = number.substring(idx+1);
            list2.add(result1+result2);
        }
        Collections.sort(list2);
        return list2.get(list2.size()-1);
    }
}