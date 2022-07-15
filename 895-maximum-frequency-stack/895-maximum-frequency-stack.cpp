class FreqStack {
public:
    unordered_map<int, int>mp;
    priority_queue<pair<int, pair<int, int>>>pq;
    int pos = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        pos++;
        mp[val]++;
        pq.push({mp[val],{pos, val}});
    }
    
    int pop() {
        int t = pq.top().second.second;
        pq.pop();
        mp[t]--;
        return t;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */