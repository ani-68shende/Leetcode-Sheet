class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            int kaju = arr[i];
            for(int j = i+1 ; j < n ; j++){
                kaju ^= arr[j];
                if(kaju == 0)count+= j-i;
            }
        }
        return count;
    }
};