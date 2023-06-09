class MinStack {
public:
    vector<int>v;
    multiset<int>s;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
        s.insert(val);
    }
    
    void pop() {
        int ele = v[v.size()-1];
        v.pop_back();
        s.erase(s.find(ele));
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        return *s.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */