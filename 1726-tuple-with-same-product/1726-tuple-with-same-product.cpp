class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long ,long long>mp;
        for(int i = 0 ;i < nums.size() ; i++){
            for(int j = i+1 ; j < nums.size() ; j++){
                mp[1LL*nums[i]*nums[j]]++;
            }
        }
        long long  sum = 0;
        for(auto x : mp){
            sum += (x.second-1)*(x.second)/2;
        }
        return sum*8;
    }
};