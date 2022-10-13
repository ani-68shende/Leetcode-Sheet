class Solution {
public:
    
    string shortestPalindrome(string s) {
        string temp(s);
        reverse(temp.begin(),temp.end());
        vector<int>ans = help(s+":"+temp);
        // for(auto x : ans)cout << x << " ";
        // cout << "\n";
        string add = s.substr(ans[ans.size()-1]);
        reverse(add.begin(),add.end());
        return add+s;
    }
    vector<int> help(string pat){
        int n = pat.size();
        vector<int>lps(n);
        lps[0] = 0; 
        int i = 1;
        int j = 0;
        while (i < n) {
            if (pat[i] == pat[j]) {
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
        return lps;
    }
    int helper(string txt, vector<int>& lps, string pat){
        int i = 0, j =0;
        while (i < txt.size()) {
            if (txt[i] == pat[j]) {
                i++,j++;
                if(j == pat.size())return 1; // lps.size()
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
        }
        return 0;
    }
};