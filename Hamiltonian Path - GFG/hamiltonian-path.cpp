//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool check(int N,int M,vector<vector<int>> Edges)

    {
        vector<int> visited(N);

        vector<vector<int>> graph(N);

        

        for(vector<int>& edge : Edges){

                graph[edge[0]-1].push_back(edge[1]-1);

                graph[edge[1]-1].push_back(edge[0]-1);

        }

        

        for(int i = 0; i < N; i++){

            if(dfs(graph,visited,i,1)){

                return true;

            }

        }

        

        return false;

    }

    

    bool dfs(vector<vector<int>>& graph,vector<int>& visited,int node,int cnt){

       if(cnt == graph.size()) return true;

       

       visited[node] = 1;

       

       for(int i : graph[node]){

           if(!visited[i] && dfs(graph,visited,i,cnt+1)) return true;

       }

       

       

        return visited[node] = 0;

    }

};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends