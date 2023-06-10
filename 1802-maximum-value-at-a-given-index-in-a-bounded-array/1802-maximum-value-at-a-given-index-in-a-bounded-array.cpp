#define ll long long int
class Solution {
public:
    ll sumNatural(ll n)
    {
        ll sum = (n * (n + 1)) / 2;
        return sum;
    }
    ll suminRange(ll l, ll r)
    {
        return sumNatural(r) - sumNatural(l - 1);
    }
    bool check(int n, int index, int xx, int num){
        ll maxSum = xx;
        ll l = index-1, r = index+1;
        maxSum -= n;
        num--;
        ll nu = num - 1, cc;
        //for left
        cc = suminRange(max((ll)0, (ll)nu-l), nu);
        // cout << cc << " ";
        maxSum -= cc;
        // for middle
        nu = num;
        // cout << nu << " ";
        maxSum -= nu;
        // for right
        nu = num - 1;
        cc = suminRange(max((ll)0, (ll)nu-(n-r)+1), nu);
        maxSum -= cc;
        // cout << cc << " maxSum : ";
        // cout << maxSum << " \n";
        return maxSum >= 0;
    }
    int maxValue(int n, int index, int maxSum) {
        ll l = 0, r = 1e11, ans = 0;
        check(8,6,20,4);
        while(l <= r){
            ll mid = l + (r-l)/2;
            if(check(n, index, maxSum, mid)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};