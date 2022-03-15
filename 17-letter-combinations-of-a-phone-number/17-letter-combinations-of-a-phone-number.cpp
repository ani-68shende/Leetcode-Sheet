vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; class Solution {
public:
    void helper(int idx, string digits, string &z, vector<string>&ans){
        if(idx == digits.size()){
            ans.push_back(z);
            return;
        }
        string r;
        r.push_back(digits[idx]);
        int d= stoi(r)-2;
        for(auto x : mappings[d]){
            z.push_back(x);
            helper(idx+1, digits, z, ans);
            z.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)return {};
        vector<string>ans;
        string z;
        helper(0, digits, z, ans);
        return ans;
    }
};