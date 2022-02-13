class Solution {
public:
    int minOperations(int n) {
        //1 3 5 7               ->1+3 = 4
        //1 3 5                 ->2
        //1 3 5 7 9             ->2+4 = 6
        //1 3 5 7 9 11          ->
        vector<int>v;
        for(int i = 0 ; i < n ; i++){
            v.push_back(2*i+1);
        }
        long long int sum = 0;
        for(int i = 0 ; i < n/2 ; i++){
            sum += (-v[i]+v[n-i-1])/2;
        }
        return sum;
    }
};