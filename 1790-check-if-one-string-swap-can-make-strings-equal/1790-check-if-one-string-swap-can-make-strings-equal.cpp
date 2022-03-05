class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int flag = 0;
        char c1, c2;
        int flag2 = 0;
        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i]!=s2[i] && flag == 0){
                c1 = s1[i];
                c2 = s2[i];
                flag++;
                flag2++;
            }
            else if(s1[i]!=s2[i] && c2 == s1[i] && c1 == s2[i]){
                flag++;
                flag2++;
            }
            else if(s1[i]!=s2[i])flag++;
        }
        cout << flag << " " << flag2 << endl;
        if(flag==2 || flag == 0){
            if(flag2== 0 || flag2 == 2)return true;
            else return false;
        }
        return false;
    }
};