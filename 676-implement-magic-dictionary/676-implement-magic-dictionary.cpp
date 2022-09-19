class MagicDictionary {
public:
    unordered_map<string, int>mp;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto x : dictionary)mp[x]++;
    }
    
    bool search(string sWe) {
        for(int i = 0 ; i < sWe.size() ; i++){
            string temp = sWe;
            for(auto x = 'a' ; x <= 'z' ; x++){
                if(x == sWe[i])continue;
                temp[i] = x;
                if(mp.find(temp)!=mp.end())return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */