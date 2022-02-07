class Solution {
public:
    int minimumSum(int num) {
        vector<int>v;
        int d = num;
        int n = 4;
        while(d>0){
            int y = d%10;
            v.push_back(y);
            d /= 10;
        }
        sort(v.begin(), v.end());
        int wq = 0, r = 0;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                wq = wq*10 + v[i];
            else
                r = r*10 + v[i];
        }
        return wq+r;
    }
};