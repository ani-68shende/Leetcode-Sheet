class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int>perm(n,0),compare(n,0);
        for(int i = 0 ; i < n ; i++){
            perm[i] = i;
            compare[i]= i;
        }
        int count = 1;
        vector<int>arr;
        for(int k = 0 ; k < 1001 ; k++){
            arr = perm;
            for(int i = 0 ; i < n ; i++){
                if(i%2 == 0){
                    arr[i] = perm[i / 2];
                }else{
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                }
            }
            perm = arr;
            if(compare == perm)return count;
            count++;
        }
        return 0;
    }
};