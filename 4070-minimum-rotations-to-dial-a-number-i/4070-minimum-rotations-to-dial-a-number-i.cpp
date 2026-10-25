class Solution {
public:
    int minRotations(string s) {
        int count = 0;
        int start = 0;
        for(int i=0;i<s.size();i++){
            int target = s[i] - 48;
            int reach1 = abs(target - start);
            int reach2 = 10 - reach1;
            start = target;
            count = count + min(reach1,reach2);
        }
        return count;
    }
};