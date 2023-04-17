class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxu = *max_element(candies.begin(), candies.end());
        vector<bool>vv;
        for(auto x : candies){
            if(x + extraCandies >= maxu){
                vv.push_back((2==2));
            }else{
                vv.push_back((1==2));
            }
        }
        return vv;
    }
};