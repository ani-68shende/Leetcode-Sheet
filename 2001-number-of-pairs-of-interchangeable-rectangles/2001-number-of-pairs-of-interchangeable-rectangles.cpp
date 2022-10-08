class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long int>mp;
        for(auto x : rectangles)mp[1.00*x[0]/x[1]*1.00]++;
        long long int count =0 ;
        for(auto x : mp)count+=x.second*(x.second-1)/2;
        return count;
    }
};