class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxu = 0;
        int count0 = 0;
        while(j < n){
            if(!nums[j])count0++;
            if(count0 > 1){
                while(i < n && nums[i]!=0){
                    i++;
                }
                i++;
                count0--;
            }
            maxu = max(maxu, j-i+1);
            j++;
        }
        return maxu;
    }
};