class Solution {
public:
    vector<int>ans;
    void dfs(int low, int high, int i, int sum){
        if(sum >= low && sum <= high){
            ans.push_back(sum);
        }
        if(sum > high || i > 9){
            return;
        }
        return dfs(low, high, i+1, sum*10+i);
    }
    vector<int> sequentialDigits(int low, int high) {
        for(auto i = 1 ; i <= 9 ; i++){
            dfs(low, high, i, 0);
        }sort(ans.begin(), ans.end());
        return ans;
    }
};