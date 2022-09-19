class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int maxu =0;
        int n = s.size();
        sort(d.begin(), d.end());
        string ans;
        for(int k = 0 ; k < d.size() ;  k++){
            string f = d[k];
            int m = f.size();
            int i = 0;
            int j = 0;
            while(i < n && j < m){
                if(s[i] == f[j]){
                    i++,j++;
                }else{
                    i++;
                }
            }
            if(j == m){
                if(maxu < m){
                    maxu = m;
                    ans = f;
                }
            }
        }return ans;
    }
};