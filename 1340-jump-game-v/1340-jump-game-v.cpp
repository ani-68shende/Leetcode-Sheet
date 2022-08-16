class Solution {
public:
    
    //finally after seeing 3 yt videos
    
    int f(int prev, int i, int d, vector<int>& arr, vector<int> & dp){
        if(dp[i]!=-1)return dp[i];
        int maxi = 0;
        for(int k = i-1 ; k >= i-d ; k--){
            if(k < 0 || k >=arr.size())continue;
            if(prev > arr[k]){
                maxi = max(maxi, 1+f(arr[k], k, d, arr, dp));   
            }else{
                break;
            }
        }
        for(int k = i+1 ; k <= i+d ; k++){
            if(k < 0 || k >=arr.size())continue;
            if(prev > arr[k]){
                maxi = max(maxi, 1+f(arr[k], k, d, arr, dp));   
            }else{
                break;
            }
        }
        return dp[i] = maxi;
    }
    int maxJumps(vector<int>& arr, int d) {
        int maxu = 0;
        vector<int>dp(arr.size(), -1);
        for(int i = 0 ; i < arr.size() ; i++){
            maxu = max(maxu, f(arr[i], i, d, arr, dp));
        }
        return maxu+1;
    }
};