class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        string temp(s);
        sort(temp.begin(), temp.end(), greater<char>());
        if(temp == s)return -1;
        next_permutation(s.begin(), s.end());
        int num = stoll(s);
        return num < n ? -1 : num;
    }
};