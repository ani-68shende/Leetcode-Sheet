class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i = 0;
        int num = 1;
        while(i < arr.size()){
            if(num <= arr[i]){
                num++;
                i++;
            }else{
                i++;
            }
        }
        return num-1;
        // return min((int)arr.size(), 1);
    }
};