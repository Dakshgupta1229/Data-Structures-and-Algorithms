class Solution {
public:
    int countVowelSubstrings(string word) {
        int count = 0;
        for(int i=0;i<word.size();i++){
            string str;
            set<char> s;
            for(int j=i;j<word.size();j++){
                if(word[j]=='a' || word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u'){
                    str+=word[j];
                    s.insert(word[j]);
                    if(str.size()>=5){
                        bool flag = false;
                        if(s.find('a')!=s.end()){
                            if(s.find('e')!=s.end()){
                                if(s.find('i')!=s.end()){
                                    if(s.find('o')!=s.end()){
                                        if(s.find('u')!=s.end()){
                                            count++;
                                            flag = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else break;
            }
        }
        return count;
    }
};