class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> m;
        int i=0;
        int j=0;
        int count = 0;
        int max_length = 0;
        while(i<fruits.size()){
            m[fruits[i]]++;
            count++;
            if(m.size()<=2){
                max_length = count;
            }
            else{
                m[fruits[j]]--;
                if(m[fruits[j]]==0) m.erase(fruits[j]);
                count--;
                j++;
            }
            i++;
        }
        if(m.size()<=2){
            if(max_length<m.size()) max_length = count;
        }
        return max_length;
    }
};