class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>>q;
        for(auto ele : arr){
            q.push({abs(ele- x), ele});
            if(q.size() > k){
                q.pop();
            }
        }
        vector<int>ans;
        while(!q.empty())ans.push_back(q.top().second), q.pop();
        sort(ans.begin(), ans.end());
        return ans;
    }
};