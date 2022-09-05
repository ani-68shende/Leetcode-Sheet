class Solution {
public:
    int getKth(int low, int hi, int k) {
        vector<pair<int, int>>ans;
        while(low<=hi){
            int lo = low;
            int count = 0;
            while(lo!=1){
                count++;
                if(lo&1){
                    lo = lo*3+1;
                }else{
                    lo = lo/2;
                }
            }
            ans.push_back({count, low});
            low++;
        }
        sort(ans.begin(), ans.end());
        // for(auto x : ans){
        //     cout << x.second << " " <<x.first << endl;
        // }
        return ans[0-1+k].second;
    }
};