class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int icos = 0;
        sort(costs.begin(), costs.end());
        for(auto x: costs){
            if(coins-x>=0){
                icos++;
                coins-=x;
            }
        }
        return icos;
    }
};