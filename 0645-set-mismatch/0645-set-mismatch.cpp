class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int sum = 0;
        int x = -1;
        for(auto x : nums)mp[x]++, sum += x;
        int num = -1;
        for(auto x : mp)if(x.second == 2){num = x.first;break;}
        int sum2 = (n*(n+1)/2);
        return {num,num+(sum2-sum)};
    }
};