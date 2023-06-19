class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxu = 0;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += gain[i];
            maxu = max(sum, maxu);
        }
        return maxu;
    }
};