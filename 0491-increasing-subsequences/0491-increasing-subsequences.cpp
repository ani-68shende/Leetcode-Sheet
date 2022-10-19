class Solution {
public:
    set<vector<int>>seta;
    void f(int i, vector<int>& nums, vector<int>temp)
    {
        if(i >= nums.size())return ;
        for(int k = i ; k < nums.size() ; k++){
            f(k+1, nums, temp);
            if(temp.size() == 0){
                temp.push_back(nums[k]);
                f(k+1, nums, temp);
            }
            else if(temp.back() <= nums[k]){
                temp.push_back(nums[k]);
                if(seta.count(temp))continue;
                seta.insert(temp);
                f(k+1, nums, temp);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
        f(0, nums, temp);
        vector<vector<int>>ss;
        for(auto x : seta)ss.push_back(x);
        return ss;
    }
};