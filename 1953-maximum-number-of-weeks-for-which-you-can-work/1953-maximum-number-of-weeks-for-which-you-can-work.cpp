class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long ans = 0;
        sort(milestones.begin(), milestones.end(),greater<int>());
        int n = milestones.size();
        for(int i = 1 ; i < n ; i++){
            ans += milestones[i];
        }
        if(milestones[0]>ans){
            return ans*2+1;
        }else if(milestones[0]==ans){
            return ans*2;
        }
        return ans+milestones[0];
    }
};