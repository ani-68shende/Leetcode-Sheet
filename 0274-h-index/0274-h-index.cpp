class Solution {
public:
    int bs(int ele, vector<int>&v){
        int low = 0, high= v.size()-1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(v[mid] >= ele){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return high; //or low
    }
    int hIndex(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        for(int i = n ; i >= 1 ; i--){
            if(n-(bs(i, v)+1) >= i)return i;
        }
        return 0;
    }
};