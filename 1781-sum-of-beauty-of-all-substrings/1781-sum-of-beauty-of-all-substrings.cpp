class Solution {
public:
    int beautySum(string s) {
        int count = 0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            unordered_map<int, int>mp;
            for(int j = i ; j < n ; j++){
                mp[s[j]]++;
                int mini = INT_MAX;
                int maxu = 0;
                for(auto x : mp){
                    mini = min(x.second, mini);
                    maxu = max(x.second, maxu);
                }
                count+= maxu-mini;
            }
        }
        return count;
    }
};