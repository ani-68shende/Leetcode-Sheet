class Solution {
public:
     // yt++
    int findTheLongestSubstring(string s) {
        unordered_map<char, int>mp;
        unordered_map<int, int>seen;
        int maxu = 0;
        int mas = 0;
        seen[0] = -1;
        mp['a']=1, mp['e']=5,mp['i']=9, mp['o']=15, mp['u']=21;
        int n = s.size();
        for(int j = 0 ; j < n ; j++){
            mas = mas^mp[s[j]];
            if(!seen.count(mas)){
                seen[mas] = j;
            }
            // cout << j << "->" << mas  << " " << j-seen[mas] << endl;
            maxu = max(maxu, j-seen[mas]);
        }
        // for(auto x : seen){
        //     cout << x.first << " " << x.second << endl;
        // }
        cout << endl;
        return maxu;
    }
};