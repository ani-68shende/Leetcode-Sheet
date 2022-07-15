class Solution {
public:
    unordered_map<string, int>mp;
    vector<string>ans;
    void f(int i,string w,  string curr){
        if(w.size() == i){
            curr.pop_back();
            ans.push_back(curr);
        }
        string temp;
        for(int k = i ; k < w.size() ; k++){
            temp += w[k];
            if(mp.find(temp)!=mp.end())
            {
                f(k+1, w, curr +  temp+" ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wD) {
        for(auto x : wD)mp[x]++;
        string curr="";
        f(0, s, curr);
        return ans;
    }
};