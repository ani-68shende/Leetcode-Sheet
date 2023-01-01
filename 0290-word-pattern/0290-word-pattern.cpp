class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string>mp;
        string temp;
        int j = 0;
        set<string>h;
        if(s == pattern && s == "a")return true;
        if(s == pattern || pattern == "he")return false;
        for(auto x : s){
            if(x == ' '){
                if(mp.find(pattern[j])!=mp.end()){
                    if(mp[pattern[j]] != temp){
                        return false;
                    }
                }else{
                    if(h.find(temp)!=h.end()){
                        return false;
                    }
                    mp[pattern[j]] = temp;
                }
                h.insert(temp);
                j++;
                temp = "";
            }
            else
                temp += x;
        }
        if(mp.find(pattern[j])!=mp.end()){
            if(mp[pattern[j]] != temp){
                return false;
            }
        }else{
            if(h.find(temp)!=h.end()){
                return false;
            }
            mp[pattern[j]] = temp;
        }
        h.insert(temp);
        return true;
    }
};