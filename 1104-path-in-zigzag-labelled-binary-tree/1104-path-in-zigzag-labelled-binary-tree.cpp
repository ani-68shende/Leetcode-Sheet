class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int>ans, v;
        while(label){
            ans.push_back(label);
            label /= 2;
        }
        vector<int>p;
        unordered_map<int, int>mp;
        for(int i = 0 ; i < 20 ; i++){
            mp[pow(2, i+1)-1] = pow(2, i);
            p.push_back(pow(2, i+1)-1);
        }
        // for(auto x : p){
        //     cout << x.first << " " << x.second << endl;
        // }
        for(int i = 1 ; i < ans.size() ; i+=2){
            int idx = lower_bound(p.begin(), p.end(),ans[i])-p.begin();
            ans[i] = (p[idx] - ans[i]) + mp[p[idx]];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};