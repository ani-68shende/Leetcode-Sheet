class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int maxu = 0;
        for(auto x : damage)maxu = max(maxu, x);
        long long sum = 0;
        int flag = 1;
        for(auto x : damage){
            if(x == maxu && flag){
                //used
                flag = 0;
                sum += (maxu > armor) ? maxu-armor : 0;
                continue;
            }
            sum += x;
        }
        return sum+1;
    }
};