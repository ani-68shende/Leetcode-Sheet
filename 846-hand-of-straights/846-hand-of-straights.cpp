class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        map<int, int>mp;
        vector<int>vv;
        for(auto x : nums){
            mp[x]++;
        }
        for(auto x : mp)vv.push_back(x.first);
        sort(nums.begin(), nums.end(), greater<int>());
        // for(auto x : vv)cout << x <<  " ";
        // cout << endl;
        for(auto xx : nums){
            int temp = xx;
            int y = k;
            if(mp.find(temp)!=mp.end() && mp[temp] != 0){
                while(y >0 && mp.find(temp)!=mp.end() && mp[temp] != 0){
                    mp[temp]--;
                    temp--;
                    // if(mp[temp] == 0){
                    //     mp.erase(temp);
                    // }
                    y--;
                }
                if(y != 0)return false;
            }
        }
        for(auto x : mp){
            if(x.second!=0) return false;
        }
        return true;
    }
};