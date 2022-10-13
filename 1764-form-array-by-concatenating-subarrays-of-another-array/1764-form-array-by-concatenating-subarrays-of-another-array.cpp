class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size(), m = groups.size();
        int i = 0;
        int count = 0;
        for(int j = 0 ; j < m ; j++){
            vector<int>s = groups[j];
            int found = false;
            while(i < n && !found){
                int k = 0;
                int d = i;
                if(nums[d]==s[k]){
                    while(d < n && k < s.size() && nums[d]==s[k]){
                        d++,k++;
                    }
                    if(k == s.size()){
                        count++;
                        found = true;
                        i=d-1;
                    }
                }
                i++;
            }
        }
        return count == m;
    }
};