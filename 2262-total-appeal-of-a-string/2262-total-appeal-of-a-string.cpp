#define ll long long 
class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        vector<ll>v(n,0);
        v[0] = 1;
        vector<ll>last(26,-1);
        last[s[0]-'a'] = 0;
        for(int i = 1 ; i < s.size() ; i++){
            v[i] = v[i-1]+1+(i-last[s[i]-'a']-1);
            last[s[i]-'a']=i;
        }
        ll sum = 0;
        for(auto x : v)sum+=x;
        return sum;
    }
};