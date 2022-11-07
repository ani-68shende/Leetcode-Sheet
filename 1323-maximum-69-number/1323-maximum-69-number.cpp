class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(auto x = 0 ; x < s.size() ; x++){
            if(s[x]!='9'){
                s[x] = '9';
                break;
            }
        }
        cout << s << endl;
        int y = stoi(s);
        return y;
    }
};