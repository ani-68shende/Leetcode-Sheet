class Solution {
public:
    //finally all edge cases removed and solved successfully yay :D
    bool isLongPressedName(string name, string typed) {
        int flag = 0;
        unordered_map<char, int>mp,mp2;
        int i = 0;
        int j = 0;
        int n = name.size();
        int m = typed.size();
        while(i < n && j < m){
            if(name[i]!=typed[j])return false;
            else{
                char ch = typed[j];
                i++;
                j++;
                while(i < n && j < m && name[i] == typed[j] && ch == name[i]){
                    i++; j++;
                }
                while(j < m && ch == typed[j]){
                    j++;
                }
            }
        }
        if(i == n &&j == m )
        return true;
        else return false;
    }
};
/*
"allleeeeeexx"
"aallleexxxxxxxxx"
"saeed"
"ssaaedd"
"alex"
"aaleex"
*/