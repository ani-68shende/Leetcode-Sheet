class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>mp;
        vector<pair<int,char>>pq;
        //pair<char,int>
        for(auto i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
        }
        for(auto x : mp){
            pq.push_back({x.second,x.first});
        }
        sort(pq.begin(), pq.end(), greater<pair<int,char>>());
        // for(auto t : pq){
        //     cout << t.first << " : " << t.second << endl;
        // }
        string s1="";
        for(auto x : pq){
            auto z = x.first;
            while(z--)
            s1.push_back(x.second);
        }
        return s1;
    }
};