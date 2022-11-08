class Solution {
public:
    int minimumOperations(vector<int>& arr) {
        vector<long long>nums;
        for(auto x : arr)nums.push_back(x);
        int i = 0, j = nums.size()-1;
        int count = 0;
        while(i < j){
            if(nums[i] == nums[j]){
                i++,j--;
            }
            if(i!= j && nums[i] > nums[j] && j-1>=0){
                nums[j-1] = nums[j-1]+nums[j];
                count++;
                j--;
            }else if(i!= j && nums[i] < nums[j] && i+1<nums.size()){
                nums[i+1] = nums[i+1]+nums[i];
                count++;
                i++;
            }
        }
        // for(auto x : nums)cout << x << " ";
        // cout << endl;
        return count;
    }
};