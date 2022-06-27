class Solution {
public:
    // minimum subarray solves the problem :D
    int maxScore(vector<int>& cp, int k) {
        int i = 0;
        int res = 1e5;
        int j = 0;
        int new_k = cp.size()-k;
        int sum = 0;
        int total = 0;
        for(auto x : cp){
            total +=  x;
        }
        res = total;
        if(k == cp.size())return total;
        while(j < cp.size()){
            sum += cp[j];
            if(j - i + 1 == new_k){
                res= min(res, sum);
                sum -= cp[i];
                i++;
            }
            j++;
        }
        return total - res;
    }
};