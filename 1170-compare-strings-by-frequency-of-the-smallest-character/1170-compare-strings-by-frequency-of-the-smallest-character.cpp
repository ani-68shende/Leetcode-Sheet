class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>worda;
        for(auto y : words){
            sort(y.begin(), y.end());
            int counta = 0;
            char ch = y[0];
            int i = 0;
            while(i < y.size() &&  ch == y[i]){
                counta++;
                i++;
            }
            worda.push_back(counta);
        }
        sort(worda.begin(), worda.end());
        vector<int>a;
        int n = worda.size();
        for(auto y : queries){
            sort(y.begin(), y.end());
            int counta = 0;
            char ch = y[0];
            int i = 0;
            while(i < y.size() &&  ch == y[i]){
                counta++;
                i++;
            }
            int key = upper_bound(worda.begin(), worda.end(), counta)-worda.begin();
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