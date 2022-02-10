class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count = 0;
        int pref_sum = 0;
        mp[0]++;
        //cout << 0 << ": " <<  mp[0] << endl;
        for(int i = 0 ; i < nums.size() ; i++){
            //cout << "round : " << i+1 << endl;
            pref_sum += nums[i];
            //cout << pref_sum << endl;
            count += mp[pref_sum-k];
            //cout << count << " " << pref_sum-k << ": " << mp[pref_sum-k] << endl;
            mp[pref_sum]++;
            //cout << pref_sum << " : " <<mp[pref_sum] << endl;
        }
        return count;
    }
};