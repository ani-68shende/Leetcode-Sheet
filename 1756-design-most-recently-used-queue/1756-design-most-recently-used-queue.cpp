class MRUQueue {
public:
    vector<int>q;
    MRUQueue(int n) {
        for(int i =0 ; i < n; i++){
            q.push_back(i+1);
        }
    }
    
    int fetch(int k) {
        int idx = k-1;
        int temp = q[idx];
        for(int i = idx+1 ; i < q.size() ; i++){
            q[i-1]=q[i];
        }
        q[q.size()-1] = temp;
        return temp;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */