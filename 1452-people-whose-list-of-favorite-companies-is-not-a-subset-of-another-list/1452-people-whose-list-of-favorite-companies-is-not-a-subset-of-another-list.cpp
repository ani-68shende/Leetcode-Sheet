class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& fc) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = fc.size();
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            unordered_map<string, int>mp;
            for(auto &x : fc[i]){
                mp[x]++;
            }
            int flag= 0;
            for(int j = 0 ; j < n ; j++){
                if(i!=j || fc[j].size() < mp.size()){
                    int count = 0;
                    for(auto &x : fc[j]){
                        if(mp.count(x))count++;
                    }
                    if(count == mp.size()){
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};