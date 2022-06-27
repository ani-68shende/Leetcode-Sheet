class Solution {
public:
    // minimum subarray solves the problem :D
    // be careful set the res = total because its the only max value possible
    int maxScore(vector<int>& cp, int k) {
        int i = 0;
        int j = 0;
        int new_k = cp.size()-k;
        int sum = 0;
        int total = 0;
        for(auto x : cp){
            total +=  x;
        }
        int res = 0;
        if(k == cp.size())return total;
        while(j < cp.size()){
            sum += cp[j];
            if(j - i + 1 == new_k){
                res= max(res, total - sum);
                sum -= cp[i];
                i++;
            }
            j++;
        }
        return res;
    }
};