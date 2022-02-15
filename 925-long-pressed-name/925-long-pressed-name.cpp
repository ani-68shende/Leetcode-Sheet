class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int flag = 0;
        unordered_map<char, int>mp,mp2;
        int i = 0;
        int j = 0;
        int n = name.size();
        int m = typed.size();
        // reverse(name.begin(), name.end());
        // reverse(typed.begin(), typed.end());
        while(i < n && j < m){
            if(name[i]!=typed[j])return false;
            else{
                cout << "First "<<  i << " " << j << " ";
                char ch = typed[j];
                i++;
                j++;
                while(i < n && j < m && name[i] == typed[j] && ch == name[i]){
                    i++; j++;
                }
                //cout << "j" << j << endl;
                while(j < m && ch == typed[j]){
                    j++;
                }
                cout <<"Second " << i << " " << j << endl;
            }
        }
        cout << i << " " << j << endl;
        cout << n << " " << m << endl;
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