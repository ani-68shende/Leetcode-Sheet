class Solution {
public:
    int helper(vector<int>&arr, int flag){
        int count = 0 , maxu = 0;
        int temp = flag;
        int n = arr.size();
        for(int i = 1 ; i < n ; i++){
            if(arr[i-1] < arr[i] && flag){
                count++;
                flag =!flag;
            }else if(arr[i-1] > arr[i] && !flag){
                count++;
                flag =!flag;
            }else{
                count = 0;
                flag =!flag;
            }
            maxu = max(count, maxu);
        }
        return maxu+1;
    }
    int maxTurbulenceSize(vector<int>& arr) {
        return max(helper(arr, 0), helper(arr, 1));
    }
};