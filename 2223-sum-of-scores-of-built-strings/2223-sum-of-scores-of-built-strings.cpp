class Solution {
public:
    long long sumScores(string s) {
        // s=s+"#"+s;
        vector<long long> pajaz = halp(s);
        long long sum = 0;
        for(int i(0) ; i < s.size() ; i++){
            // cout << pajaz[i] << " ";
            sum += pajaz[i];
        }
        return sum+s.size();
    }
    vector<long long> halp(string str)
    {
        int n = str.length();
        int L, R, k;
        vector<long long>pajaz(str.size());
        L = R = 0;
        for (int i = 1; i < n; ++i)
        {
            if (i > R)
            {
                L = R = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                pajaz[i] = R-L;
                R--;
            }
            else
            {
                k = i-L;
                if (pajaz[k] < R-i+1)
                    pajaz[i] = pajaz[k];
                else
                {
                    L = i;
                    while (R<n && str[R-L] == str[R])
                        R++;
                    pajaz[i] = R-L;
                    R--;
                }
            }
        }
        return pajaz;
    }
};