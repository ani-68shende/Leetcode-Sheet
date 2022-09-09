class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int>ans(nums.size(),-1);
        int win = 2*k+1;
        long long int sum = 0;
        int i = 0;
        int j(0);
        int kkko(k);
        while(j < nums.size()){
            sum += nums[j];
            if(j-i+1 == win){
                int yy = sum/(1+j-i);
                ans[kkko] = yy;
                kkko++;
                
                // post 
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};