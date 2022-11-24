class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>>mp;
        vector<vector<string>>ans;
        int n = strings.size();
        
        
        vector<char>alpha;
        int jj = 0;
        map<char, int>ind;
        for(char x = 'a' ; x <= 'z' ; x++)
        {
            alpha.push_back(x);
            ind[x] = jj;
            jj++;
        }
        
        unordered_map<string, int>str;
        
        for(auto x : strings)str[x]++;
        
        for(int j = 0 ; j < n ; j++){
            string temp = strings[j];
            for(int i = 0 ; i <= 26 ; i++){
                string ss;
                for(int k = 0 ; k < temp.size() ; k++){
                    char ch =temp[k];
                    ss.push_back(char(((int)(i+ch-'a'))%26+'a'));
                }
                if(str.find(ss)!=str.end()){
                    for(int kk = 0 ; kk < str[ss] ; kk++){
                        mp[temp].push_back(ss);
                    }
                    str.erase(ss);
                }
            }
        }
        for(auto x : mp){
            vector<string>t;
            for(auto y : x.second){
                t.push_back(y);
            }
            ans.push_back(t);
        }
        return ans;
    }
};