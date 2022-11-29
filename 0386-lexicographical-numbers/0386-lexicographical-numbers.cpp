class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>ans;vector<int>res;
        int j = 1;
        while(n--)ans.push_back(to_string(j++));
        sort(ans.begin(),ans.end());
        for(auto x : ans)res.push_back(stoi(x));
        return res;
    }
};