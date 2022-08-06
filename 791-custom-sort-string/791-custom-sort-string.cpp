class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int>mp;
        for(int i = 0 ; i < order.size(); i++)
            mp[order[i]] = i;
        string h = "";
        string elser = "";
        for(auto x : s){
            if(!mp.count(x)){
                h.push_back(x);
            }else{
                elser.push_back(x);
            }
        }
        for(int i = 0 ; i < elser.size() ; i++){
            // booble.ai
            for(int j = i ; j < elser.size() ; j++){
                if(mp[elser[i]] >= mp[elser[j]]){
                    swap(elser[i], elser[j]);
                }
            }
        }
        return h + elser;
    }
};