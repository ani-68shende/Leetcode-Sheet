#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> st;
        string y = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '*')
            {
                st.push(s[i]);
            }
            else
            {
                if (!st.empty() && s[i] == '*')
                {
                    st.pop();
                }
            }
        }
        while (!st.empty())
        {
            y += st.top();
            st.pop();
        }
        reverse(y.begin(), y.end());
        return y;
    }
};