class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int >pajaz = help(s);
        for(auto x : pajaz)cout << x << " ";
        cout << "\n";
        return pajaz[n-1] && (pajaz[n-1]%(n-pajaz[n-1])==0);
    }
    vector<int> help(string pat){
        int n = pat.size();
        vector<int>b(n);
        b[0] = 0; 
        int i = 1;
        int j = 0;
        while (i < n) {
            if (pat[i] == pat[j]) {
                j++;
                b[i] = j;
                i++;
            }
            else 
            {
                if (j != 0) {
                    j = b[j - 1];
                }
                else
                {
                    b[i] = 0;
                    i++;
                }
            }
        }
        return b;
    }
};