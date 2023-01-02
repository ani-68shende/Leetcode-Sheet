class Solution {
public:
    static bool cmp(string &a, string &b){
        return a.size() > b.size();
    }
    int longestCommonSubsequence(string &text1, string &text2) {
        int n = text1.size();
        int m = text2.size();
        int dp[n+1][m+1];
        string s;
        for(int i = 0 ; i < n+1 ; i++){
            for(int j = 0 ; j < m+1 ; j++){
                if(i == 0|| j == 0){
                    dp[i][j] = 0;
                }
                else if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    // s.push_back(text1[i-1]);
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        // cout << s << endl;
        return dp[n][m];
    }
    int findLUSlength(vector<string>& strs) {
        int maxu = 0;
        sort(strs.begin(), strs.end(),cmp);
        // for(auto &x : strs)cout << x << " ";
        // cout << endl;
        if(strs[0].size() > strs[1].size())return strs[0].size();
        for(int i = 0 ; i < strs.size() ; i++){
            int flag = 1;
            string x = strs[i];
            for(int j = 0 ; j < strs.size() ; j+=1){
                if(i == j)continue;
                if(longestCommonSubsequence(x, strs[j]) == x.size()){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                return x.size();
            }
        }
        return -1;
    }
};