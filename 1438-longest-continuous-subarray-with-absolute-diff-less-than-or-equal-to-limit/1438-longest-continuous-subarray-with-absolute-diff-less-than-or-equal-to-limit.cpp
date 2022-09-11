#define ll long long int
// sorry its overkill
class Solution {
public:
    int minVal(int x, int y) { return (x < y) ? x : y; }
    int getMid(int s, int e) { return s + (e - s) / 2; }
    int RMQUtil(int *st2, int ss, int se, int qs, int qe, int index)
    {
        if (qs <= ss && qe >= se)
            return st2[index];
        if (se < qs || ss > qe)
            return INT_MAX;
        int mid = getMid(ss, se);
        return minVal(RMQUtil(st2, ss, mid, qs, qe, 2 * index + 1),
                      RMQUtil(st2, mid + 1, se, qs, qe, 2 * index + 2));
    }
    int RMQ(int *st2, int n, int qs, int qe)
    {
        if (qs < 0 || qe > n - 1 || qs > qe)
        {
            cout << "Invalid Input";
            return -1;
        }

        return RMQUtil(st2, 0, n - 1, qs, qe, 0);
    }
    int constructST1Util(vector<int> &arr, int ss, int se,
                         int *st2, int si)
    {
        if (ss == se)
        {
            st2[si] = arr[ss];
            return arr[ss];
        }
        int mid = getMid(ss, se);
        st2[si] = minVal(constructST1Util(arr, ss, mid, st2, si * 2 + 1),
                        constructST1Util(arr, mid + 1, se, st2, si * 2 + 2));
        return st2[si];
    }

    int *constructST1(vector<int> &arr, int n)
    {
        int x = (int)(ceil(log2(n)));
        int max_size = 2 * (int)pow(2, x) - 1;
        int *st2 = new int[max_size];
        constructST1Util(arr, 0, n - 1, st2, 0);
        return st2;
    }
    int MaxUtil(int *st, int ss, int se, int l, int r, int node)
    {
        if (l <= ss && r >= se)
            return st[node];
        if (se < l || ss > r)
            return -1;
        int mid = getMid(ss, se);

        return max(MaxUtil(st, ss, mid, l, r,
                           2 * node + 1),
                   MaxUtil(st, mid + 1, se, l,
                           r, 2 * node + 2));
    }
    int getMax(int *st, int n, int l, int r)
    {
        if (l < 0 || r > n - 1 || l > r)
        {
            printf("Invalid Input");
            return -1;
        }

        return MaxUtil(st, 0, n - 1, l, r, 0);
    }
    int constructSTUtil(vector<int> &arr, int ss, int se,
                        int *st, int si)
    {
        if (ss == se)
        {
            st[si] = arr[ss];
            return arr[ss];
        }
        int mid = getMid(ss, se);

        st[si] = max(constructSTUtil(arr, ss, mid, st,
                                     si * 2 + 1),
                     constructSTUtil(arr, mid + 1, se,
                                     st, si * 2 + 2));

        return st[si];
    }
    int *constructST(vector<int> &arr, int n)
    {
        int x = (int)(ceil(log2(n)));
        int max_size = 2 * (int)pow(2, x) - 1;
        int *st = new int[max_size];
        constructSTUtil(arr, 0, n - 1, st, 0);
        return st;
    }
    int longestSubarray(vector<int>& nums, int l) {
        ll i = 0;
        ll n = nums.size();
        int *st = constructST(nums, n);
        int *st2 = constructST1(nums, n);
        ll ans = 0;
        int j = 0;
        ll sum = 0;
        while (j < n)
        {
            if (getMax(st, n, i, j) - RMQ(st2, n, i, j) > l)
            {
                i++;
            }
            else
            {
                // cout << i << " " << j << endl;
                ans = max(ans, 1LL*(j - i + 1));
            }
            // cout << j << " " << sum << " " << getMax(st, n, i, j) << endl;
            j++;
        }
        return ans;
    }
};