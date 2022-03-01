// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long countPairs(int N, int x, vector<int> num){
        // code here 
        int ans = 0;
        unordered_map<string,int>mp;
       for(int i=0;i<N;i++)
       {
           string s = to_string(num[i]);
           mp[s]++;
       }
       string y = to_string(x);
       int m = y.size();
       for(int i=1;i<m;i++)
       {
           string left = y.substr(0,i);
           string right = y.substr(i);
           
           if(left==right) ans+=mp[left]*(mp[left]-1);
           else ans+=mp[left]*mp[right]; 
       }
       return ans;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends