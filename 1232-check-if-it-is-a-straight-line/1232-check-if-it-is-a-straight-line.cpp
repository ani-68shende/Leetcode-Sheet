class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
       int n = co.size();
        if(n == 2)return true;
        for(int i = 2 ; i < co.size() ; i++){
            if( (co[i][1] - co[i-1][1]) * (co[i-1][0] - co[i-2][0]) != (co[i][0] - co[i-1][0]) * (co[i-1][1] - co[i-2][1]) )return false;
        }
        return true;
    }
};