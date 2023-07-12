class Solution {
public:
    unordered_map<char, vector<char>>mp;
    int mod = 1e9+7;
    vector<char>v{'a','e','i','o','u'};
    int f(char prev, int n, vector<vector<int>> & dp)
    {
        if(n == 0)return 1;
        int count = 0;
        if(dp[n][prev-'a']!=-1)return dp[n][prev-'a'];
        for(auto x : mp[prev])
        {
            count += f(x, n-1, dp);
            count = count % mod;
        }
        return dp[n][prev-'a'] = count;
    }
    int countVowelPermutation(int n) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        mp['a'] = {'e'};
        mp['e'] = {'a', 'i'};
        mp['i'] = {'a','e','o','u'};
        mp['o'] = {'i','u'};
        mp['u'] = {'a'};
        char prev = 'a';
        int cc = 0;
        for(int i = 0 ; i < 5 ; i++)
        {
            vector<vector<int>>dp(n+1, vector<int>(26, -1));
            int vi = f(v[i], n-1, dp);
            cc += vi;
            cc = cc %mod;
        }
        return cc;
    }
};