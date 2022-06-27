class Solution {
public:
    int largestCombination(vector<int>& ca) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int n = ca.size();
        vector<int>v(26,0);
        for(auto i = 0 ; i < n ; i++){
            int j = 0;
            int bb = ca[i];
            while(bb > 0){
                int r = bb%2;
                bb /= 2;
                v[j] += r;
                j++;
            }
        }
        return *max_element(v.begin(), v.end());
    }
};