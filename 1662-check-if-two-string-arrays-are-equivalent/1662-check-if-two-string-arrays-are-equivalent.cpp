class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a1, a2;
        for(auto x : word1)a1+=x;
        for(auto x : word2)a2+=x;
        return a1 == a2;
    }
};