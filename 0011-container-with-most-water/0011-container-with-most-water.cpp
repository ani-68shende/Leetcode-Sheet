class Solution {
public:
    int maxArea(vector<int>& he) {
        int i = 0;
        int n = he.size();
        int j = n-1;
        int omax =0;
        while(i <j){
            omax = max(omax, (j-i)*(min(he[i],he[j])));
            if(he[i]<=he[j]){
                i++;
            }else{
                j--;
            }
        }
        return omax;
    }
};