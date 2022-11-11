class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int j = 0, i = 0;
        while(i<nums.size()){
            int count =0 ;
            int prev = nums[i];
            while(i < nums.size() && prev == nums[i]){
                i++;
                count++;
            }
            if(count>=2){
                nums[j] = prev;j++, nums[j]= prev;j++;
            }else{
                nums[j] = prev;j++;
            }
        }
        // for(auto x : nums)cout << x << " ";
        return j;
    }
};