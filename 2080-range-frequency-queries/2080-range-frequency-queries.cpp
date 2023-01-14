class RangeFreqQuery {
public:
    map<int, vector<int>>mp;
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(auto i = 0 ; i < n ; i++){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto start = lower_bound(mp[value].begin(), mp[value].end(),left);
        auto finish = upper_bound(mp[value].begin(), mp[value].end(),right);
        return finish-start;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */