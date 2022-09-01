class Solution {
public:
    // harder than a hard problem needed to watch yt videos for better understanding --> go from left to right...
    string smallestSubsequence(string s) {
        vector<int>visited(26, 0);
        vector<int>lastIndex(26, 0);
        for(int i(0) ; i < s.size() ; i++){
            lastIndex[s[i]-'a'] = i;
        }
        stack<char>st;
        for(int i(0) ; i < s.size() ; i++){
            if(visited[s[i]-'a'])continue;
            //see first two characters of the first testcase for this
            while(!st.empty() && st.top() > s[i] && i < lastIndex[st.top()-'a']){
                visited[st.top()-'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i]-'a'] = 1;
        }
        string str;
        while(!st.empty()){
            str = st.top() + str;
            st.pop();
        }
        return str;
    }
};