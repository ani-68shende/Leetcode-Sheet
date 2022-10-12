class Solution {
public:
    int largestPerimeter(vector<int>& v) {
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 2 ; i < v.size() ; i++){
            if(v[i]+v[i-1] > v[i-2]){
                return v[i]+v[i-1]+v[i-2];
            }
        }
        return 0;
        }
};