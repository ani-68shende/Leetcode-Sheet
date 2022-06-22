class Solution {
public:
    int thirdMax(vector<int>& nu) {
        int maxu = INT_MIN;
        unordered_map<int,int>mp;
        int n = nu.size();
        set<int>s;
        vector<int>nums;
        for(auto x : nu){
            s.insert(x);
        }
        for(auto y : s){
            nums.push_back(y);
        }
        priority_queue<int>pq;
        if(nums.size() <= 2){
            return *max_element(nums.begin(), nums.end());
        }
        for(int i  = 0 ; i < nums.size() ; i++){
            //cout << nums[i] << " ";
            pq.push(nums[i]);
        }
        int y = 0;
        while(y < 2){
            y++;
            pq.pop();
        }
        return pq.top();
    }
};