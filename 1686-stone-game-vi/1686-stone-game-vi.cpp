class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        vector<vector<int>>v;
        for(int i = 0 ;i < a.size() ; i++){
            v.push_back({a[i]+b[i] , a[i] , b[i]});
        }
        sort(v.begin(), v.end(), greater<vector<int>>());
        int alice = 0, bob =0 ;
        for(int i = 0 ; i < a.size() ; i++){
            if(i%2){
                bob += v[i][2];
            }else{
                alice += v[i][1];
            }
        }
        if(alice == bob){
            return 0;
        }else if(alice < bob){
            return -1;
        }
        return 1;
    }
};