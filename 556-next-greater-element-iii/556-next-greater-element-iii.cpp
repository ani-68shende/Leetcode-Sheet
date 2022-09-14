class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        int num = stoll(s);
        return num <= n ? -1 : num;
    }
};