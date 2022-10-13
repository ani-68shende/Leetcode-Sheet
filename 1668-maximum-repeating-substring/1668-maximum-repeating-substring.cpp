class Solution {
public:
    int maxRepeating(string txt, string s) {
        int j = 0;
        int ini_length = s.size();
        while(s.size() <= txt.size())s+=s;
        int n = s.size();
        vector<int>lps(n);
        lps[0] = 0; 
        int i = 1;
        while (i < n) {
            if (s[i] == s[j]) {
                j++;
                lps[i] = j;
                i++;
            }
            else 
            {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        for(auto x : lps)cout << x << " ";
        cout << "\n";
        int maxu = 0;
        i = 0, j =0;
        while (i < txt.size()) {
            if (txt[i] == s[j]) {
                i++,j++;
            }
            else 
            {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
            if(j%ini_length == 0)maxu = max(maxu, j/ini_length);
        }
        return maxu;
    }
};