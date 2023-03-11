class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        n = pow(2, n);
        vector<int> ans;
        for (int i=0; i<n; i++) 
            ans.push_back(start ^ i ^ (i>>1));
        return ans;
    }
};