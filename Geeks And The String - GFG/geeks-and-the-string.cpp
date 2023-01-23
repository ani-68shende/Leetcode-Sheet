//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        stack<char>st;
        for(int i = 0 ; i < s.size() ; i++){
            if(st.size() && st.top() == s[i]){
                while(i < s.size() and st.size() && st.top() == s[i]){
                    st.pop();
                    i++;
                }
                i--;
            }else{
                st.push(s[i]);
            }
        }
        string temp;
        while(st.size()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        if(temp == "")return "-1";
        return temp;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends