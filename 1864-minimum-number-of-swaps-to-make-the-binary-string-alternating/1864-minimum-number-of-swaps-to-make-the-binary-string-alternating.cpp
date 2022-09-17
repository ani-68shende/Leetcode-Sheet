class Solution {
public:
    int minSwaps(string s) {
        int c0(0), c1(0);
        for(auto x : s)c0 += x== '0', c1 += x=='1';
        if(abs(c0-c1)>=2)return -1;
        string h = "";
        if(c0 > c1){
            int flag = 0;
            for(int i = 0 ; i <s.size() ; i++){
                if(!flag){
                    h+='0',flag = !flag;
                }else{
                    h+='1',flag = !flag;
                }
            }
        }else if(c0 < c1){
            
            int flag = 0;
            for(int i = 0 ; i <s.size() ; i++){
                if(!flag){
                    h+='1',flag = !flag;
                }else{
                    h+='0',flag = !flag;
                }
            }
        }else{
            string h1, h2;
            int flag = 0;
            for(int i = 0 ; i < s.size() ; i++){
                if(!flag){
                    h1+='1',h2+='0',flag = !flag;
                }else{
                    h1+='0',h2+='1',flag = !flag;
                }
            }
            int maxu = 0;
            int co0(0), co1(0);
            for(int i = 0 ; i < s.size() ; i++){
                if(s[i]!=h1[i])co0++;
            }
            for(int i = 0 ; i < s.size() ; i++){
                if(s[i]!=h2[i])co1++;
            }
            return min(co0, co1)/2;
        }
        int counto = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]!=h[i])counto++;
        }
        return counto/2;
    }
};