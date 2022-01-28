class Solution {
public:
    int longestConsecutive(vector<int>& d) {
        set<int>s;
        vector<int>nums;
        unordered_map<int, int>mp;
        // the only case which we have to handle is the case of repeating numbers otherwise the problem is easy
        for(auto f : d)s.insert(f);
        for(auto t : s)nums.push_back(t);
        for(auto x: nums){
            mp[x]++;
        }
        int maxu = 0;
        int n = nums.size();
        if(n <=1)return n;
        for(int i = 0 ; i < n ; i++){
            int count = 0;
            if(mp[nums[i]-1]!=0)continue;
            else {
                while(mp[nums[i]]!=0){
                    count++;
                    nums[i]++;
                }
                maxu = max(maxu, count);
            }
        }
        return maxu;
    }
};