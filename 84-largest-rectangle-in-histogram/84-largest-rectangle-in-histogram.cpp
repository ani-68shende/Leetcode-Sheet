class Solution {
public:
    vector<int> smaller1(vector<int>he){
        vector<int>ans;
        stack<int>st;
        for(int i = 0 ; i < he.size(); i++){
            while(st.size() && he[st.top()] >= he[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(st.top());
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> smaller2(vector<int>he){
        vector<int>ans;
        stack<int>st;
        for(int i = he.size()-1 ; i >= 0 ; i--){
            while(st.size() && he[st.top()] >= he[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(he.size());
            }else{
                ans.push_back(st.top());
            }
            st.push(i);
        }//nashe op
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int largestRectangleArea(vector<int>& he) {
        vector<int>prev_small = smaller1(he);
        vector<int>next_small = smaller2(he);
        // for(auto x : next_small)cout << x << " ";
        int overall_max = 0;
        for(int i = 0 ; i < he.size() ; i++){
            overall_max = max(overall_max, (next_small[i]-prev_small[i] - 1)*he[i]);
        }
        // cout << endl;
        return overall_max;
    }
};