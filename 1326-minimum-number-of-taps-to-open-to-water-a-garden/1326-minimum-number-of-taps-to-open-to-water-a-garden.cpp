class Solution {
public:
    // a good greedy problem see yt indepth
    int minTaps(int n, vector<int>& ranges) {
        int maxu(0), mini(0), open(0);
        while(maxu<n){
            for(int i = 0 ; i < ranges.size() ; i++){
                if(i-ranges[i]<=mini && maxu < i+ranges[i])maxu = i+ranges[i];
            }
            if(mini == maxu)return -1;
            mini = maxu;
            open++;
        }return open;
    }
};