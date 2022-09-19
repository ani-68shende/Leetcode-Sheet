class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        vector<int>f;
        for(int i = 1 ; i <= 2000 ; i++)f.push_back(((i+1)*i)/2);
        int idx = upper_bound(f.begin(), f.end(), grades.size())-f.begin();
        return idx;
    }
};