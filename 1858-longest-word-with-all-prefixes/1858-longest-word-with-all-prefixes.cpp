class Solution {
public:
    string longestWord(vector<string>& words) {
        vector<string>ansl;
        unordered_map<string, int>mp;
        sort(words.begin(), words.end());
        string temp = "";
        mp[temp]++;
        int maxu = 0;
        for(int i = 0 ; i < words.size() ; i++){
            string str = words[i];
            str.pop_back();
            if(mp.count(str)){
                mp[words[i]] = 1 + mp[str];
                maxu = max(maxu, mp[words[i]]);
            }
        }
        for(auto x : mp){
            if(x.second == maxu){
                ansl.push_back(x.first);
            }
        }
        if(ansl.size() ==0)return "";
        sort(ansl.begin(),ansl.end());
        return *ansl.begin();
    }
};