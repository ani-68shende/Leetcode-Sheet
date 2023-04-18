class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        string s;
        int q1=0;
        int q2=0;
        for(int i = 0; i < m+n ; i++)
        {
            if(i%2== 0 && q1<n)
            {
                s.push_back(w1[q1]);
                q1++;
            }
            else if(i%2== 1 && q2<m)
            {
                s.push_back(w2[q2]);
                q2++;
            }
        }
        while(q1<=n-1)
        {
            s.push_back(w1[q1]);
            q1++;
        }
        while(q2<=m-1)
        {
            s.push_back(w2[q2]);
            q2++;
        }
        return s;
    }
};