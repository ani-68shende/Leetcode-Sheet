#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<vector<int>> nas;
        int n = matches.size();
        int m = matches[0].size();
        vector<int> winner, loser;
        unordered_map<int, int> winners, losers;
        for (auto x : matches)
        {
            winners[x[0]]++;
            losers[x[1]]++;
        }
        for (auto x : winners)
        {
            if (losers.find(x.first) == losers.end())
            {
                winner.push_back(x.first);
            }
        }
        for (auto x : losers)
        {
            if (x.second == 1)
            {
                loser.push_back(x.first);
            }
        }
        sort(winner.begin(), winner.end());
        sort(loser.begin(), loser.end());
        nas.push_back(winner);
        nas.push_back(loser);
        return nas;
    }
};