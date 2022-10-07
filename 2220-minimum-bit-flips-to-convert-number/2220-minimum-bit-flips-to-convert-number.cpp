#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);
    }
};