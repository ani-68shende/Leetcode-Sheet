class TimeMap {
public:
    map<string, vector<pair<int, string>>>mp;
    TimeMap() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key))return "";
        int tt=0;
        int d = -1;
        int start = 0;
        int end = mp[key].size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(mp[key][mid].first == timestamp){
                return mp[key][mid].second;
            }
            else if(mp[key][mid].first < timestamp){
                d = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        if(d == -1)return "";
        return mp[key][d].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */