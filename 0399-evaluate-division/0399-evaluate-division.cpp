//will do later
class Solution {
public:
    
    
    double dfs( unordered_map< string , vector<pair<string,double>>>&ma,string start,string end,unordered_map<string,int>& vis)
    {
        vis[start]++;
        
        if(ma.count(start)==0)
           return -1.0;
        
        if(start==end)return 1.0;
        
        double not_determined=-1;

        for(auto a:ma[start])
        {
            
            if(vis.count(a.first)==0)
            {
             
                auto rem=dfs(ma,a.first,end,vis);
                
                if(rem!=-1)
                    return rem*a.second;
                
            }
        }
        
        vis.erase(start);
        
        return not_determined;
        
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n=equations.size();
        
        unordered_map< string , vector<pair<string,double>> > ma;
        
        for(int i=0;i<n;i++)
        {
            
            ma[equations[i][0]].push_back({equations[i][1],values[i]});
            ma[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        
        vector<double> ans;
        
        for(auto a:queries)
        {
            unordered_map<string,int> vis;
            ans.push_back(dfs(ma,a[0],a[1],vis)); 
        }
        
        return ans;
        
    }
};