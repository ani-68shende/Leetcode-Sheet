class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>s;
        string pp = "Push";string pu = "Pop";
        map<int, int> mp;
        for(auto x : target){
            mp[x]++;
        }
        vector<int>asrle;
        for(auto i(1) ; i <= n ; i++){
            if(asrle == target)break;
            if(mp.find(i)!=mp.end()){
                asrle.push_back(i);
                s.push_back(pp);
            }else{
                s.push_back(pp);
                s.push_back(pu);
            }
        }
        return s;
    }
};