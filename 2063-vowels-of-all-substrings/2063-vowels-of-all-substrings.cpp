#define ll long long
unordered_map<char, int>mp;
class Solution {
public:
    long long countVowels(string s) {
        int n = s.size();
        mp['a']++,mp['i']++,mp['u']++, mp['o']++,mp['e']++;
        vector<ll>v(n+1,0);
        for(int i = 0 ; i < s.size() ; i++){
            if(mp.find(s[i])==mp.end())
                v[i+1] += v[i];
            else
                v[i+1] += v[i]+i+1;
        }
        ll sum = 0;
        for(auto x : v)sum+=x;
        return sum;
    }
};