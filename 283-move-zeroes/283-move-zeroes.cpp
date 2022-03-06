class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int mark = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i]!=0)
            {
                nums[mark] = nums[i];
                mark++;
            }
        }
        for(int i = mark ; i < n ; i++)
        {
            nums[i] = 0;
        }
    }
};