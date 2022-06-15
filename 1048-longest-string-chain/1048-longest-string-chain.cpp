class Solution {
public:
    int res = 0;
    static bool cmp(const string & s1, const string & s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int>mp;
        for(int i = 0 ; i < words.size() ; i++){
            string temp = words[i];
            for(int j = 0 ; j < temp.size() ; j++){
                string pre = temp.substr(0,j) + temp.substr(1+j);
                mp[temp] = max(mp[temp], mp.find(pre) == mp.end() ? 1 : mp[pre]+1);
            }
            res = max(res, mp[temp]);
        }
        return res;
    }
};