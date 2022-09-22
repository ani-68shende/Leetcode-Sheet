class Solution {
public:
    //see first dicuss its simply god
    vector<int> constructArray(int n, int k) {
        vector<int>ans;
        int i = 1;
        int j = n;
        bool isj = false;
        if(k%2 == 0)isj=true;
        int flagu = 1;
        for(int kk = 0 ;kk < n ; kk++){
            if(k>0){
                if(flagu){
                    ans.push_back(i),flagu=0;
                    i++;
                }else{
                    ans.push_back(j),flagu=1;
                    j--;
                }
                k--;
            }else{
                if(isj){
                    ans.push_back(j),j--;
                }else{
                    ans.push_back(i),i++;
                }
            }
        }
        return ans;
    }
};