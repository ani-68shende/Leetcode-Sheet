class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int>y(nums);
        int k = 0,i=0;
        int j = 0;
        sort(y.begin(),y.end(),greater<int>());
        vector<int>ans(n, 0);
        for(i = 1 ; i < n ; i+=2){
            ans[i]=y[k];
            k++;
        }
        for(i = 0 ; i < n ; i+=2){
            ans[i]=y[k];
            k++;
        }
        nums = ans;
    }
};