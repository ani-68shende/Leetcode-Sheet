#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    string gibPalindrome(string s)
    {
        int l = s.size();
        unordered_map<int, int> m;
        for (int i = 0; i < l; i++)
            m[s[i] - '0']++;
        char gib[l];
        string hh;
        int front = 0;
        for (int i = 9; i >= 0; i--)
        {
            if (m[i] & 1)
            {
                gib[l / 2] = char(i + 48);
                m[i]--;
                while (m[i] > 0)
                {
                    gib[front] = char(i + 48);
                    gib[l - front - 1] = char(i + 48);
                    m[i] -= 2;
                    front++;
                }
            }
            else
            {
                while (m[i] > 0)
                {
                    gib[front] = char(i + 48);
                    gib[l - front - 1] = char(i + 48);
                    m[i] -= 2;
                    front++;
                }
            }
        }
        for (int i = 0; i < l; i++)
            hh.push_back(gib[i]);
        return hh;
    }
    string largestPalindromic(string num)
    {
        vector<int> v(10, 0);
        for (int i = 0; i < num.size(); i++)
            v[num[i] - '0']++;
        int sum = 0;
        for (auto x : v)
        {
            sum += x;
        }
        if (v[0] == sum)
            return "0";
        if (v[0] + 1 == sum)
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == 1)
                {
                    string gg = "";
                    gg.push_back(i + '0');
                    return gg;
                }
            }
        }
        string ans = "";
        char ch;
        int maxu = 0;
        int maxu1 = 0;
        char ch2 = '0';
        for (int i = 1; i < 10; i++)
        {
            if (v[i] % 2 && v[i] > maxu && ch2 < i + '0')
            {
                maxu1 = v[i];
                ch2 = i + '0';
            }
        }
        cout << maxu1 << " " << ch2 << endl;
        for (int i = 0; i < 10; i++)
        {
            if (v[i] % 2 == 0)
            {
                for (int j = 0; j < v[i]; j++)
                {
                    ans += i + '0';
                }
            }
        }
        vector<pair<int, int>> hrad;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] % 2)
            {
                hrad.push_back({i, v[i]});
            }
        }
        sort(hrad.begin(), hrad.end(), greater<pair<int, int>>());
        string ff = "";
        int sizer = 0;
        for (int i = 0; i < hrad.size(); i++)
        {
            for (int j = 0; j < hrad[i].second - sizer; j++)
            {
                ff.push_back(hrad[i].first + '0');
            }
            sizer = 1;
        }
        cout << ans << " " << ff << endl;
        return gibPalindrome(ans + ff);
    }
};