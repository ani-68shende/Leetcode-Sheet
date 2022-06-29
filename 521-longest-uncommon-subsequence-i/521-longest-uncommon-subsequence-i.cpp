class Solution {
public:
    int findLUSlength(string X, string Y) {
        if(X == Y)return -1;
        int m = X.size();
        int n = Y.size();
        return max(m,n);
    }
};