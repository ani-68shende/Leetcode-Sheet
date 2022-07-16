class RLEIterator {
public:
    vector<pair<int, int>>m;
    int i = 0;
    RLEIterator(vector<int>& encoding) {
        for(int i = 1 ; i < encoding.size() ; i+=2){
            m.push_back({encoding[i],encoding[i-1]});
        }
    }
    
    int next(int n) {
        int k = n;
        while(i < m.size() && k){
            if(m[i].second>0){
                int gg = min(k, m[i].second);
                k -= gg;
                m[i].second -= gg;
            }
            else if(m[i].second == 0)
            i++;
        }
        if(k == 0)return m[i].first;
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */