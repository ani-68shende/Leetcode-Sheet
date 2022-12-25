class Solution {
public:
    int i = 0, j = 0;
    bool flag = false;
    int m,n;
    set<pair<int, int>>s;
    Solution(int M, int N) {
        m = M, n = N;
    }
    
    vector<int> flip() {
        while(1){
            int i = rand()%m;
            int j = rand()%n;
            if(!s.count({i,j})){
                s.insert({i,j});
                return {i,j};
            }
        }
    }
    
    void reset() {
        s.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */