class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        map<int,int> m;
        for(int i=0;i<digits.size();i++) m[digits[i]]++;
        int count = 0;
        for(int i=100;i<=999;i++){
            map<int,int> m1;
            int num = i;
            int first = num%10;
            num = num/10;
            int second = num%10;
            num = num/10;
            int third = num%10;
            num = num/10;
            m1[first]++;
            m1[second]++;
            m1[third]++;
            bool flag = true;
            for(auto p:m1){
                int ele = p.first;
                int freq = p.second;
                if(m.find(ele)!=m.end()){
                    if(m[ele]>=freq){

                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag==true && i%2==0){
                count++;
            }
        }
        return count;
    }
};