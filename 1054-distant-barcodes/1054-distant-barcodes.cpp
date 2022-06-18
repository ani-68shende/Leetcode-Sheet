class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
    }
    vector<int> rearrangeBarcodes(vector<int>& bar) {
        map<int, int>mp;
        for(auto x : bar){
            mp[x]++;
        }
        vector<pair<int, int>>v;
        for(auto x : mp){
            v.push_back({x.second, x.first});
        }
        sort(v.begin(), v.end(), cmp);
        vector<int>temp;
        for(auto x : v){
            while(x.first>0){
                temp.push_back(x.second);
                x.first--;
            }
        }
        vector<int>y(bar.size());
        int y1 = 0;
        int i = 0;
        while(i < bar.size()){
            y[i] = temp[y1];
            y1++;
            i = i + 2;
        }
        i = 1;
        while(i < bar.size()){
            y[i] = temp[y1];
            y1++;
            i = i + 2;
        }
        return y;
    }
};