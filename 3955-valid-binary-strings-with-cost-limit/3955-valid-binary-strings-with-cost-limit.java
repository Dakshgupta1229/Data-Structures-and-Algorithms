class Solution {

    void generate(int n,int k,String str,int sum,List<String> list){
        if(str.length()>0 && str.charAt(str.length()-1)=='1') sum = sum + str.length()-1;
        if(n==str.length()){
            if(sum<=k) list.add(str);
            return;
        }
        generate(n,k,str+'0',sum,list);
        if(str.length()==0) generate(n,k,str+'1',sum,list);
        else if(str.length()>0 && str.charAt(str.length()-1)!='1') generate(n,k,str+'1',sum,list);
    }

    public List<String> generateValidStrings(int n, int k) {
        List<String> list = new ArrayList<>();
        generate(n,k,"",0,list);
        return list;
    }
}