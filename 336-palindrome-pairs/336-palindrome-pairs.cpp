class Solution {
public:
    // got this soln in latest discuss -> one without trie
    bool isPalindrome(string &str){
        int i = 0;
        int n = str.size();
        while(i < n/2){
            if(str[n-i-1] != str[i])return false;
            i++;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<string, int>mp;
        for(int i = 0 ; i < words.size() ; i++){
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            mp[temp] = i;
        }
        int n = words.size();
        vector<vector<int>>as;
        for(int i = 0 ; i < n ; i++){
            string str = words[i];
            for(int j = 0 ; j <= str.size(); j++){
                //for the partitions
                string prefix = str.substr(0, j);
                string suffic = str.substr(j); // i.e. i -> end
                if(prefix.size() && isPalindrome(prefix) && mp.count(suffic) && i!= mp[suffic]){
                    as.push_back({mp[suffic], i});
                }             
                if(isPalindrome(suffic) && mp.count(prefix) && i!= mp[prefix]){
                    as.push_back({i, mp[prefix]});
                }
            }
        }
        return as;
    }
};