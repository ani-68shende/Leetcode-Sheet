class Solution {
public:
    int solve(string &s,char b,int &k){
       int left=0,res=0,size=s.size(),cnt=0;
      for(int i=0;i<size;i++){
            if(s[i]!=b)
                cnt++;
            while(cnt>k){
                if(s[left]!=b)
                    cnt--;
                left++;
            }
            res=max(i-left+1,res);
        }
        return res;
    }
    int characterReplacement(string s, int k) {
        set<char>setsa;
        for(auto x : s)setsa.insert(x);
        int maxu = 0;
        for(auto x : setsa){
            maxu = max(maxu, solve(s, x, k));
        }
        return maxu;
    }
};