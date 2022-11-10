class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        vector<pair<int,char>>st;
        int level = 1;
        for(int i = 0 ; i < s.size() ; i++){
            if(!st.size()){
                st.push_back({1,s[i]});
            }else{
                if(st.size() && st.back().first == k-1 && s[i] == st.back().second){
                    st.pop_back();
                }
                else{
                    if(s[i] == st.back().second){
                        st.back().first++;                    
                    }else{
                        st.push_back({1,s[i]});
                    }
                }
            }
        }
        string res;
        for (auto p : st) {
            res.append(p.first, p.second);
        }
        return res;
    }
};