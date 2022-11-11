class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int>v;
        int maxu = 0;
        for(int i = heights.size()-1 ; i>= 0 ; i--){
            if(maxu < heights[i]){
                v.push_back(i);
                maxu = heights[i];
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};