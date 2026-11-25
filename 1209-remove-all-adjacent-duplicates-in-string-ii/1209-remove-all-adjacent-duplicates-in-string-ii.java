class Pair{
    char first;
    int second;
    Pair(char first,int second){
        this.first = first;
        this.second = second;
    }
}

class Solution {
    public String removeDuplicates(String s, int k) {
        Stack<Pair> st = new Stack<>();
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(st.size()==0){
                st.push(new Pair(ch,1));
            }
            else{
                char ch2 = st.peek().first;
                if(ch2==ch){
                    int freq = st.peek().second;
                    st.pop();
                    st.push(new Pair(ch2,freq+1));
                }
                else st.push(new Pair(ch,1));
            }
            if(st.size()>0){
                int fr = st.peek().second;
                if(fr==k) st.pop();
            }
        }
        StringBuffer str = new StringBuffer();
        while(st.size()>0){
            char ch = st.peek().first;
            int n = st.peek().second;
            while(n>0){
                str.append(ch);
                n--;
            }
            st.pop();
        }
        str.reverse();
        return str.toString();
    }
}