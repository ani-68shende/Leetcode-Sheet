class Solution {
public:
    int trap(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

            //main solution starts from here
        int n = nums.size();
        if(n==0)
        return 0;
        int result = 0;
        vector<int>left(n,0),right(n,0);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i = 1 ; i < n ; i++)
        {
            left[i] = max(left[i-1],nums[i]);
        }
        for(int i = n-2 ; i >= 0; i--)
        {
            right[i] = max(right[i+1],nums[i]);
        }
        for(int i = 0 ; i < n ; i++)
        {
            cout << min(left[i],right[i]) - nums[i] << endl;
            result += min(left[i],right[i]) - nums[i];
        }
        return result;
    }
};