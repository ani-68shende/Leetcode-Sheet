class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int maxu = 0;
        int i = 0;
        int j = 0;
        int n = customers.size();
        int sum = 0;
        for(int k = 0 ; k < n ; k++){
            if(!grumpy[k]){
                sum += customers[k];
            }
        }
        int res = 0;
        while(j < n){
            if(grumpy[j])
            res += customers[j];
            if(j-i+1 == minutes){
                maxu = max(maxu, res);
                if(grumpy[i]){
                    res -= customers[i];
                }
                i++;
            }
            j++;
        }
        maxu += sum;
        return maxu;
    }
};