class Solution {
public:

    void reverse(string &str,int i,int j){
        while(i<=j){
            swap(str[i],str[j]);
            i++;
            j--;
        }
    }

    string reverseParentheses(string s) {
        stack<int> st;
        string str = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(str.size());
            }
            else if(s[i]==')'){
                int n = st.top();
                reverse(str,n,str.size()-1);
                st.pop();
            }
            else str = str + s[i];
        }
        cout<<str;
        return str;
    }
};