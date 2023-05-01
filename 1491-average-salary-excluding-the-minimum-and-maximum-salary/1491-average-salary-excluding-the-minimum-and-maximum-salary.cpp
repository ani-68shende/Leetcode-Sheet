class Solution {
public:
    double average(vector<int>& v) {
        int mini = *min_element(v.begin(), v.end());
        int maxu = *max_element(v.begin(), v.end());
        int sum = accumulate(v.begin(), v.end(), 0);
        return double((sum-(maxu+mini))/(v.size() - 2.00));
    }
};