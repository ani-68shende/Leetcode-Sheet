class Solution {
public:
    bool checkIfPangram(string sen) {
        set<char>s;
        for(auto y : sen)
            s.insert(y);
        return s.size() == 26;
    }
};