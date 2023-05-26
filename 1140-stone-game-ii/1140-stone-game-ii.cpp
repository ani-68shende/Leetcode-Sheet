// do it later
class Solution {
public:
    
    pair<int,int> help(vector<int>& piles,int lo,int  m,vector<vector<pair<int,int>>>& dp)
    {

     if(lo==piles.size())
     {
         
         pair<int,int> pr={0,0};
         
         return pr;
     }
        
        if(dp[lo][m].first!=-1)return dp[lo][m];
        
        
       pair<int,int> ans={INT_MIN,INT_MIN}; 
        
        int sum=0;
        
      for(int p=1;p<=2*m;p++)
      {
          
          int index=lo+p-1;
          
          if(index==piles.size())break;
          
         
          sum+=piles[index];
          
          auto nxt=help(piles,index+1,std::max(m,p),dp);
          
          if(ans.first<sum+nxt.second)
          {
            
              ans.first=sum+nxt.second;
              
              ans.second=nxt.first;
          }
          
      }
        
       return dp[lo][m]=ans; 
    
    }
    
    
    int stoneGameII(vector<int>& piles) {
        
        vector<vector<pair<int,int>>> dp(piles.size()+1,vector<pair<int,int>>(1000,{-1,-1}));
        
        return help(piles,0,1,dp).first;
        
    }
};