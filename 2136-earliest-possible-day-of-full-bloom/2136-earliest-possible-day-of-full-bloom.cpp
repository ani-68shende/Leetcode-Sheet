#include<bits/stdc++.h>
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>>v;
        for(auto i = 0 ; i < plantTime.size() ; i++){
            v.push_back({growTime[i], plantTime[i]});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int maxu = INT_MIN;
        int result = 0;
        for(auto c : v){
            result+=c.second;
            maxu=max(maxu, result+c.first);
        }
        return maxu;
    }
};