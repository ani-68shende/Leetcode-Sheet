class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0 ;
        int j = arr.size()-1;
        int mid = 0;
        while(i <= j){
            mid = (j+i)>>1;
            if(arr[mid] < arr[mid+1]){
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }
        return i;
    }
};