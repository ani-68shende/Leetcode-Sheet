class Solution {
public:
    //array substring with atmost 2 distinct items
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int j = 0;
        int sum = 0;
        unordered_map<int, int>mp;
        int maxu = 0;
        int n = fruits.size();
        while(j < n){
            mp[fruits[j]]++;
            if(mp.size() > 2){
                while(mp.size() > 2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0)mp.erase(fruits[i]);
                    i++;
                }
            }
            maxu = max(maxu, j-i+1);
            j+=1;
        }
        return maxu;
        // unordered_map<int, int>mp;
        // vector<int>vv;
        // for(auto x : fruits)mp[x]++;
        // for(auto x : mp)vv.push_back(x.second);
        // sort(vv.begin(), vv.end());
        // if(vv.size() == 1)return vv[0];
        // return vv[vv.size()-1]+vv[vv.size()-2];
    }
};