class Solution {
public:
    
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // next greater element ki jai
        stack<int>s;
        int n = heights.size();
        vector<int>ans(n,  0);
        for(int i = n - 1; i >= 0 ; i-=1){
            while(s.size() && s.top() <= heights[i]){
                s.pop();
                ans[i]+=1;
            }
            if(s.size()){
                ans[i]++;
            }
            s.push(heights[i]);
        }
        return ans;
    }
};