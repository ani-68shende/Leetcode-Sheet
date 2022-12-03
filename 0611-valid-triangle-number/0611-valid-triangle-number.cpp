class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count(0);
        if(nums.size() < 3)return 0;
        sort(nums.begin(), nums.end(),greater<int>());
        for(int i = 0 ; i < nums.size() - 2 ; i++){
            int left = i+1, right = nums.size()-1;
            while(left < right){ // if we put equal to then it will not make any sense as we are pointing to the same object
                if(nums[i] < nums[left] + nums[right]){
                    count += right - left;
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return count;
    }
};