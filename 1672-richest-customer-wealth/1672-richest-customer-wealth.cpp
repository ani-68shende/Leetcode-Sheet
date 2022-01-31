class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum = 0;
        for(auto x : accounts){
            int ini = accumulate(x.begin(), x.end(),0);
            sum = max(ini, sum);
        }
        return sum;
    }
};