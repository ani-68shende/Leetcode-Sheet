class TreeAncestor {
public:
    vector<vector<int>>v;
    TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>> par(20, vector<int>(n));
        for (int i = 0; i < n; i++) par[0][i] = parent[i];
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < 20; j++){
                if (par[j - 1][i] == -1) par[j][i] = -1;
                else par[j][i] = par[j - 1][par[j - 1][i]];
            }
        }
        v = par;
    }
    int getKthAncestor(int node, int k) {
        for (int j = 21; j >= 0 ; j--) {
            if ((k >> j) & 1) {
                node = v[j][node];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */