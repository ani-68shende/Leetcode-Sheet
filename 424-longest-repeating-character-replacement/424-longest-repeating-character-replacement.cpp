class Solution {
public:
    // max consective ones ka variation
    int solve(string &s,char ch,int &k){
        int i = 0;
        int j = 0;
        int n = s.size();
        int count = 0;
        int maxu = 0;
        while(j < n){
            if(s[j]!=ch)count+=1;
            if(count > k){
                while(count > k){
                    if(s[i]!=ch)count--;
                    i++;
                }
            }
            maxu = max(maxu, j-i+1);
            j++;
        }
        return maxu;
    }
    int characterReplacement(string s, int k) {
        set<char>setsa;
        for(auto x : s)setsa.insert(x);
        int maxu = 0;
        for(auto ch : setsa){
            maxu = max(maxu, solve(s, ch, k));
        }
        return maxu;
    }
};