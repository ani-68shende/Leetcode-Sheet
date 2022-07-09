class Solution {
public:
    
    //prajjwa is likely to read this thats why writing this solution spaciously
    
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int suma = 0;
        
        int x1 = startPos[0];
        
        int y1 = startPos[1];
        
        int x2 = homePos[0];
        
        int y2 = homePos[1];
        
        
        if(x1 < x2){
            
            for(int i = x1 + 1 ; i <= x2 ; i++){
                suma += rowCosts[i];
            }
            
        }else{
            
            for(int i = x2 ; i <= x1 - 1 ; i++){
                suma += rowCosts[i];
            }
            
        }
        if(y1 < y2){
            
            for(int i = y1 + 1 ; i <= y2 ; i++){
                suma += colCosts[i];
            }
            
        }else{
            
            for(int i = y2 ; i <= y1 - 1 ; i++){
                suma += colCosts[i];
            }
            
        }
        
        return suma;
    }
};