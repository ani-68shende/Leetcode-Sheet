class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        map<int, int>mp;for(int i = 0 ; i < arr.size() ; i++)mp[arr[i]] = i;
        int maxu = *max_element(arr.begin(), arr.end());
        return mp[maxu];
    }
};