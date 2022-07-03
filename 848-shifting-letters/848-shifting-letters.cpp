class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<int>suff(n, 0);
        suff[n-1]=shifts[n-1];
        for(int i = n-2 ; i>=0 ; i--){
            suff[i] %= 26;
            suff[i] = (suff[i+1] + shifts[i])%26;
        }
        // for(auto x : suff)cout << x << " ";
        // cout << "\n";
        string g = "";
        for(int i = 0 ; i < n ; i++){
            char t = s[i];
            int y = s[i]-'a';
            int u = (y+suff[i])%26;
            g.push_back(u+'a');
        }
        return g;
    }
};