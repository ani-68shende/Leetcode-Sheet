class CustomStack {
public:
    vector<int>v;
    int y;
    int top;
    CustomStack(int maxSize) {
        y = maxSize;
        v.resize(maxSize);
        top = -1;
    }
    
    void push(int x) {
        if(top< y-1){
        top++;
        v[top] = x;
        }
    }
    
    int pop() {
        if(top <= -1){
            return -1;
        }
        int temp = top;top--;
        return v[temp];
    }
    
    void increment(int k, int val) {
        int mni = min(k-1, top);
        for(int i = 0 ;i <= mni ; i++){
            v[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */