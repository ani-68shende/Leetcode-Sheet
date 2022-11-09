class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s == t)return false;
        int n = s.size();
        int m = t.size();
        if((m == 1 && n ==0) || (m ==0 && n == 1))return true;
        if(abs(n-m)>=2)return false;
        if(abs(m-n) == 0){
            int flag = 0;
            for(int i = 0 ; i < n ;i++){
                if(s[i]!= t[i])flag++;
            }
            return flag == 1;
        }
        if(n > m){
            int i(0),j(0);
            int flag = 0;
            while(i < n && j <m){
                if(s[i]!=t[j])flag++,i++;
                else i++,j++;
            }
            if((i == n && j ==m && flag==1) || (i == n-1 && j ==m)){
                return true;
            }else{
                return false;
            }
        }else{
                int i(0),j(0);
                int flag = 0;
                while(i < n && j <m){
                    if(s[i]!=t[j])flag++,j++;
                    else i++,j++;
                }
                if((i == n && j ==m && flag==1) || (i == n && j ==m-1)){
                    return true;
                }else{
                    return false;
                }
            }
        return false;
    }
};