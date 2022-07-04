class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>worda;
        for(auto y : words){
            sort(y.begin(), y.end());
            unordered_map<char, int>main;
            for(auto x : y){
                main[x]++;
            }
            worda.push_back(main[y[0]]);
        }
        sort(worda.begin(), worda.end());
        vector<int>a;
        int n = worda.size();
        for(auto y : queries){
            sort(y.begin(), y.end());
            unordered_map<char, int>main;
            for(auto x : y){
                main[x]++;
            }
            int maxui = main[y[0]];
            int key = upper_bound(worda.begin(), worda.end(), maxui)-worda.begin();
            a.push_back(n-key);
        }
        // for(auto x : mp){
        //     v.push_back({x.first, x.second})
        // }
        // sort(v.begin(), v.end());
        // int maxu = v[0].second;
        return a;
    }
};