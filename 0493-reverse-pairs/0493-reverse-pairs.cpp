#define ll long long int
class Solution {
public:
    ll merge(vector<ll> &v, ll s, ll mid, ll e) {
      vector<ll> temp;
      ll i = s, j = mid + 1;
      ll total =0;
      while (i <= mid && j <= e) {
        if (1LL*v[i] > 1LL*2*v[j]) {
            total+=mid-i+1;
          j++;
        } else {
          i++;
        }
      }
      for(i = s; i <= e ; i++){
          temp.push_back(v[i]);
      }
    sort(temp.begin(),temp.end());
      for (ll i = s; i <= e; i++) {
        v[i] = temp[i - s];
      }
      return total;
    }

    ll mergesort(vector<ll> &v, ll s, ll e) {
      int count = 0;
      if (s < e) {
        ll mid = (s + e) / 2;
        count += mergesort(v, s, mid);
        count += mergesort(v, mid + 1, e);
        count += merge(v, s, mid, e);
      }
      return count;
    }
    int reversePairs(vector<int>& nums) {
        vector<ll>v;
        for(auto x : nums)v.push_back(x);
        int n = v.size();
        return mergesort(v, 0, n - 1);
    }
};