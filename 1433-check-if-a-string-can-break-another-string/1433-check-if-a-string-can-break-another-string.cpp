class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int flag1 = 0, flag2 = 0, n = s2.size();
        for(int i = 0 ; i < n ; i++){
            if(s1[i]< s2[i]){
                flag1 = 1;
            }
        }
        if(flag1 == 0)return true;
        for(int i = 0 ; i < n ; i++){
            if(s1[i]> s2[i]){
                flag2 = 1;
            }
        }
        if(flag1 == 1 && flag2 == 0)return true;
        return false;
    }
};