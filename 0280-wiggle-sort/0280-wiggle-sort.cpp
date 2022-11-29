class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int>y(nums);
        int k = 0,i=0;
        int j = n-1;
        sort(y.begin(),y.end());
        vector<int>ans(n, 0);
        for(i = 0 ; i < n ; i+=2){
            ans[i]=y[k];
            k++;
        }
        for(i = 1 ; i < n ; i+=2){
            ans[i]=y[j];
            j--;
        }
        nums = ans;
    }
};