//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        map<long long, int>mp;
        int maxu = 0;
        long long sum = 0;
        int i = 0;
        for(i = 0 ; i < n ; i++){
            sum += A[i];
            if(mp.count(sum)){
                maxu = max(maxu, i-mp[sum]);
            }
            if(sum == 0){
                maxu = max(maxu, i+1);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        // if(mp.count(sum)){
        //     maxu = max(maxu, i-mp[sum]);
        // }
        return maxu;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends