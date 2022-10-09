class Solution {
public:
    int tres = 0;
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>temp(arr);
        sort(temp.begin(), temp.end());
        map<int, int>mp1, mp2;
        for(int i(0) ; i < arr.size() ; i++){
            if(mp1 == mp2){
                tres++;
            }
            mp1[temp[i]]++;
            mp2[arr[i]]++;
        }
        return tres;
    }
};