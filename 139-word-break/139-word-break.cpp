class Solution {
public:
    unordered_map<string, int>mp;
    bool f(int i,string w,vector<string>& wD, vector<int>& dp){
        if(w.size() == i)return true;
        string temp;
        if(dp[i]!=-1)return dp[i];
        for(int k = i ; k < w.size() ; k++){
            temp += w[k];
            if(mp.find(temp)!=mp.end())
            {
                if(f(k+1, w, wD, dp))return dp[k] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wD) {
        for(auto x : wD)mp[x]++;
        vector<int>dp(s.size(), -1);
        return f(0, s, wD, dp);
    }
};