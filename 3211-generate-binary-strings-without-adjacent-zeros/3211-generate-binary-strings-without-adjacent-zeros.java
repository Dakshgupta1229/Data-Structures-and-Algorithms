class Solution {

    void substring(int num,String str,List<String> list){
        if(str.length()==num){
            list.add(str);
            return;
        }
        substring(num,str+'1',list);
        if(str.length()==0) substring(num,str+'0',list);
        else if(str.length()>0 && str.charAt(str.length()-1)!='0') substring(num,str+'0',list);
    }

    public List<String> validStrings(int n) {
        List<String> list = new ArrayList<>();
        substring(n,"",list);
        // Set<
        return list;
    }
}