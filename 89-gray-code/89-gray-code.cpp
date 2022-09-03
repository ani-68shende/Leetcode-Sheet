class Solution {
public:
    // discuss se uthaya
    // logic op
    vector<int> grayCode(int n) {
        n = pow(2, n);
        vector<int> ans;
        for (int i=0; i<n; i++) 
            ans.push_back(i^(i>>1));
        return ans;
    }
};