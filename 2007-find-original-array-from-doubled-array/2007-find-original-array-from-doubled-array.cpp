class Solution {
public:
    vector<int> findOriginalArray(vector<int>& ch) {
        unordered_map<int,int>mp;
        int n = ch.size();
        if(n%2)return {};
        for(int i= 0 ;i < n ; i++){
            mp[ch[i]]++;
        }
        vector<int>keys;
        for(auto x : mp){
            keys.push_back(x.first);
        }
        sort(keys.begin(), keys.end(), [](int i, int j){return abs(i) < abs(j);});
        //final ans vector
        vector<int>ans;
        for(auto c : keys){
            if(mp[c] > mp[2*c])return {};
            else{
                for(int i = 0 ; i < mp[c] ; i++){
                    ans.push_back(c);
                    mp[2*c]--;
                }
            }
        }
        return ans;
    }
};
