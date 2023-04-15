class Solution {
public:
    
    int help(vector<vector<int>>& piles,int index,int k,int n,vector<vector<int>>& dp)
    {
        
        if(index==n||k==0)
            return 0;
        
        if(dp[index][k]!=-1)
            return dp[index][k];
        
        
        int siz=piles[index].size();
        
        int er=INT_MIN;
        
        int sum=0;

        for(int i=0;i<min(siz,k);i++)
        {
        
            sum+=piles[index][i];
            
            int tim=help(piles,index+1,k-(i+1),n,dp);
            
            if(tim>=0)
            {
                er=max(er,tim+sum);
            }
            
        }
        
        return dp[index][k]=max(er,help(piles,index+1,k,n,dp));
     
    }
    
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        vector<vector<int>> dp(piles.size(),vector<int>(k+1,-1));
        
        return help(piles,0,k,piles.size(),dp);
        
    }
};