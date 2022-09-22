static const auto io_sync_off = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {

public:
    string reverseWords(string s) {
        int idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + idx, s.begin() + i);
                idx = i + 1;
            }
        }
        reverse(s.begin() + idx, s.end());
        return s;
    }
};