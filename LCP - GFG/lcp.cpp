// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string LCP(string ar[], int n)
    {
        // code here
        int count = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            int siz = ar[i].size();
            count = min(count, siz);
        }
        int counta = 0;
        int flag = 0;
        string ha = "";
        for(int i = 0 ; i < count ; i++){
            char ch = ar[0][i];
            if(flag == 1)break;
            for(int j = 0 ; j < n ; j++){
                if(ar[j][i]!=ch){
                    flag = 1;
                    break;
                }
            }
            if(flag!=1){
                ha.push_back(ch);
            }
        }
        return ha.size() == 0 ? "-1" : ha;
    }
};

// { Driver Code Starts.

int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends