class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        stack<char> outer;
        stack<char> parenthesis;
        for(int i=0;i<s.size();i++){
            if(outer.size()==0 && s[i]=='(') outer.push('(');
            else if(s[i]=='('){
                parenthesis.push('(');
                result.push_back('(');
            }
            else if(parenthesis.size()>0 && s[i]==')'){
                parenthesis.pop();
                result.push_back(')');
            }
            else if(outer.size()>0 && s[i]==')') outer.pop();
        }
        return result;
    }
};