class Solution {
public:
    // don't know how it wworks but it works
    int minimumSwap(string s1, string s2) {
        if(s1.size()!=s2.size())return -1*1;
        // unordered_map<char, int>mp;
        // for(auto x : s1 )mp[x]++;
        // for(auto x : s2)mp[x]++;
        // for(auto x : mp)if(x.second&1)return -1;
        int x=0, y=0, xy =0 , yx = 0;
        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i] == 'x' && s2[i] == 'x')x+=2;
            else if(s1[i] == 'y' && s2[i] == 'y')y+=2;
            else if(s1[i] == 'x' && s2[i] == 'y')xy++,x++,y++;
            else if(s1[i] == 'y' && s2[i] == 'x')yx++,x++,y++;
        }
        if(x&1 || y&1)//doing the work of map !!
            return -1;
        return xy/2+yx/2+xy%2+yx%2;
    }
};