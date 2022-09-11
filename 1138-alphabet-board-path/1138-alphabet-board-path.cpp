class Solution
{
public:
    string alphabetBoardPath(string target)
    {
        unordered_map<char, pair<int, int>> mp;
        for (int i = 'a'; i <= 'z'; i++)
        {
            mp[i] = {(i - 'a') / 5, (i - 'a') % 5};
        }
        string ans = "";
        // god move not from discuss op->means from discuss
        target = 'a' + target;
        int n = target.size();
        for (int i = 1; i < target.size(); i++)
        {
            char ch1 = target[i - 1];
            char ch2 = target[i];
            int x = mp[ch2].first - mp[ch1].first;
            int y = mp[ch2].second - mp[ch1].second;
            // oh bhai order bhi matter karra yaha toh
            if (x < 0)
            {
                for (int i = 0; i < -x; i++)
                {
                    ans += 'U';
                }
            }
            if (y < 0)
            {
                for (int i = 0; i < -y; i++)
                {
                    ans += 'L';
                }
            }
            if (x > 0)
            {
                for (int i = 0; i < x; i++)
                {
                    ans += 'D';
                }
            }
            if (y > 0)
            {
                for (int i = 0; i < y; i++)
                {
                    ans += 'R';
                }
            }
            ans+='!';
        }
        return ans;
    }
};