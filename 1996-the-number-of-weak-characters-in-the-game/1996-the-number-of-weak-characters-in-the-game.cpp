class Solution {
public:
    static bool cmp(vector<int> & a, vector<int> & b){
        if(a[0] == b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int count = 0;
        sort(properties.begin(), properties.end(), cmp);
        int mxtnfb = INT_MIN;
        for(int i = properties.size()-1 ; i >= 0 ; i--){
            if(properties[i][1] < mxtnfb){
                count++;
            }
            mxtnfb = max(mxtnfb, properties[i][1]);
        }
        return count;
    }
};