#define ll long long int
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ll n = nums.size();
        if(n < 4)return {};
        for(ll i = 0 ; i < n ; i++){
            for(ll j = i+1 ; j < n ; j++){
                ll sum = nums[i]+nums[j];
                ll k = target-sum;
                ll left = j+1;
                ll right = n-1;
                while(left < right){
                    if(nums[left]+nums[right]<k){
                        left++;
                    }else if(nums[left]+nums[right]>k){
                        right--;
                    }else{
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        ans.push_back(temp);
                        //            can be made n-1 as well
                        while(left < right && temp[2] == nums[left])left++;
                        while(left < right && temp[3] == nums[right])right--;
                    }
                }
                //for me this is great no confusion now onwards
                while(j + 1 < n && nums[j+1] == nums[j])j++;
            }
            while(i + 1 < n && nums[i+1] == nums[i])i++;
        }
        return ans;
    }
};