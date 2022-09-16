#define ll long long
class NumArray {
public:
    int n;
    vector<ll> seg;
    vector<ll>arr;
    NumArray(vector<int>& nums) {
        n = nums.size();
        for(auto x : nums){
            arr.push_back(x*1LL);
        }
        seg.resize(4 * n);
        build(0, 0, n - 1, arr, seg);
    }
    
    void update(int index, int val) {
        update(0, 0, n-1, index, val, seg);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right, seg);
    }
    void update(ll ind, ll low, ll high, ll i, ll val, vector<ll> &seg)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        ll mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val, seg);
        else
            update(2 * ind + 2, mid + 1, high, i, val, seg);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    // low high changes
    ll query(ll ind, ll low, ll high, ll l, ll r, vector<ll> &seg)
    {
        // no overlap [l r] low high OR low high [l r]
        if (high < l || r < low)
        {
            return 0;
        }
        // full overlap [l low high r]
        if (l <= low && high <= r)
        {
            return seg[ind];
        }
        ll mid = low + (high - low) / 2;
        ll left = query(ind * 2 + 1, low, mid, l, r, seg);
        ll right = query(ind * 2 + 2, mid + 1, high, l, r, seg);
        return left+right;
    }

    void build(ll ind, ll low, ll high, vector<ll> &arr, vector<ll> &seg)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        ll mid = low + (high - low) / 2;
        build(ind * 2 + 1, low, mid, arr, seg);
        build(ind * 2 + 2, mid + 1, high, arr, seg);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */