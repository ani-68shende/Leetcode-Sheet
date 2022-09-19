class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_map<string, int>mp;
        sort(words.begin(), words.end());
        int maxucount = 0;
        for(int i = 0 ; i < words.size() ; i++){
            if(mp.find(words[i]) !=mp.end() )continue;
            string temp = words[i];
            temp.pop_back();
            if(mp.find(temp)!=mp.end()){
                mp[words[i]] = mp[temp]; //not adding one as it is going to be added afterwards 
            }
            mp[words[i]]++;
        }
        int maxu = 0;
        vector<string>ans;
        for(auto x : mp){
            if(x.second == x.first.size())
            maxu = max(maxu, x.second);
        }
        for(auto x : mp){
            if(maxu == x.second && x.second == x.first.size()){
                ans.push_back(x.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans.size() ? ans[0] : "";
    }
};