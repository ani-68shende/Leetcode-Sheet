class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        long sum = 0;
        int n = arr.size();
        int flag = 1;
        for(int i = 0 ; i < n; i++){
            long total = 0;
            flag = !flag;
            for(int j = i ; j < n ; j+=1){
                    total += arr[j];
                    if(j%2==0 && !flag){
                        sum += total;
                    }else if(j%2 && flag){
                        sum += total;
                    }
                }
        }
        return sum;
    }
};