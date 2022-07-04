class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int>mp;
        int n = senders.size();
        for(int i = 0 ; i < n ; i++){
            int count =1 ;
            for(auto x : messages[i]){
                if(x == ' ')
                    count++;
            }
            mp[senders[i]] += count;
        }
        int maxu = 0;
        for(auto x : mp){
            maxu = max(maxu, x.second);
        }
        vector<string>max_names;
        for(auto x : mp){
            if(x.second == maxu)max_names.push_back(x.first);
        }
        sort(max_names.begin(), max_names.end(), greater<string>());
        return max_names[0];
        
    }
};