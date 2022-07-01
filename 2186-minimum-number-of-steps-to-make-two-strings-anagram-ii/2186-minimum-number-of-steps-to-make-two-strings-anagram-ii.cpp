class Solution {
public:
    int minSteps(string s, string t) {
        int i = 0;
        int j = 0;
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        int n = s.size();
        int m = t.size();
        int count = 0;
        vector<int>v(26,0), e(26,0);
        for(int i = 0 ; i < s.size() ; i++){
            v[s[i]-'a']++;
        }
        for(int i = 0 ; i < t.size() ; i++){
            e[t[i]-'a']++;
        }
        for(int i = 0 ; i < 26 ; i++){
            count += abs(v[i]-e[i]);
        }
        return count;
    }
};