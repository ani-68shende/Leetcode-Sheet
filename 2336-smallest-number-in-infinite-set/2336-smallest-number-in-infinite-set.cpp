class SmallestInfiniteSet
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    map<int, int> s;
    SmallestInfiniteSet()
    {
        for (int i = 1; i < 2005; i++)
        {
            pq.push(i);
            s[i]++;
        }
    }

    int popSmallest()
    {
        int ans = pq.top();
        pq.pop();
        s.erase(ans);
        return ans;
    }

    void addBack(int num)
    {
        if (s.find(num) == s.end())
        {
            s[num]++;
            pq.push(num);
        }
    }
};