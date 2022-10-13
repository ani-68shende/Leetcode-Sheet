class Solution {
public:
    int repeatedStringMatch(string txt, string pat) {
        string temp = "";
        int count =0;
        vector<int> lps = help(pat);
        while(temp.size() < pat.size())count++,temp+=txt;
        if(helper(temp,lps, pat)!=0)
            return count;
        count++;
        temp+=txt;
        // cout << temp << endl;
        if(helper(temp,lps,pat)!=0)
            return count;
        return -1;
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