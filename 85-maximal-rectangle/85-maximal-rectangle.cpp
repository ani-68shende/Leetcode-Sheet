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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lays_maxx = 0;
        vector<int>pref(m, 0);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j]== '1'){
                    pref[j] += (matrix[i][j])-'0';
                }else{
                    pref[j] = 0;
                }
            }
            lays_maxx = max(lays_maxx, largestRectangleArea(pref));
        }
        return lays_maxx;
    }
};